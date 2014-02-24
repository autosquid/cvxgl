#include <iostream>
#include <string>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range.hpp>
#include <iterator>


int main(int argc, char ** argv)
{
    std::string greeting("Hello World");
    boost::copy(boost::make_iterator_range(greeting.begin(), greeting.end()),
            std::ostream_iterator<std::string::value_type>(std::cout, ""));
}



