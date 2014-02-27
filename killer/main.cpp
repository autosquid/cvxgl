#include <iostream>
#include <string>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range.hpp>
#include <iterator>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "cvxgl.hpp"


int hell()
{
    std::string greeting("Hello World");
    boost::copy(boost::make_iterator_range(greeting.begin(), greeting.end()),
            std::ostream_iterator<std::string::value_type>(std::cout, ""));
    return 0;
}


glm::mat3 test_intrinsic_data()
{
    float intrinsic[] =  { 1.8742872389462805e+003, 0., 9.5950000000000000e+002, 0.,
       1.8742872389462805e+003, 5.3950000000000000e+002, 0., 0., 1. };
    return glm::make_mat3(intrinsic);
}


int main(int argc, char ** argv){
    auto intrinsic = test_intrinsic_data();
    auto im_size = glm::ivec2(1920, 1080);
    auto gl_pram = cvxgl::cv2gl(intrinsic, im_size);

    std::cout<<"from cv: viewport:"<<std::endl;
    boost::copy(boost::make_iterator_range(glm::value_ptr(gl_pram.first),
                glm::value_ptr(gl_pram.first) + 4),
            std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;

    std::cout<<"from cv: perspective:"<<std::endl;
    boost::copy(boost::make_iterator_range(glm::value_ptr(gl_pram.second),
                glm::value_ptr(gl_pram.second) + 4),
            std::ostream_iterator<float>(std::cout, " "));

    std::cout<<std::endl;

    auto intrinsic_r = cvxgl::gl2cv(
            gl_pram.first,
            gl_pram.second[0],
            gl_pram.second[1]);

    std::cout<<"recovered cv: intrinsic:"<<std::endl;
    std::copy(glm::value_ptr(intrinsic_r), glm::value_ptr(intrinsic_r) + 9,
            std::ostream_iterator<float>(std::cout," "));

    std::cout<<std::endl;
}

