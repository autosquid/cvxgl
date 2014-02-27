#ifndef _CHAOJIWUDI_SUPER_PAIN_KILLER_BY_UU
#define _CHAOJIWUDI_SUPER_PAIN_KILLER_BY_UU
#include <glm/glm.hpp>
#include <utility>
#include <math.h>
#include <glm/gtc/matrix_transform.hpp>

namespace cvxgl{
    typedef std::pair<glm::ivec4, glm::vec4> GL_PARAM;

    GL_PARAM cv2gl(
            glm::mat3 intrinsic,
            glm::ivec2 im_size
            ){
        int width = im_size[0];
        int height = im_size[1];
        float uc = intrinsic[0][2];
        float vc = intrinsic[1][2];
        float r = 1;
        float f = std::min(intrinsic[0][0], intrinsic[1][1]);
        float dx = f/intrinsic[0][0];
        float dy = f/intrinsic[1][1];
        float near_clip = 0.1;
        float far_clip = 200.0;

        glm::ivec4 viewport = glm::ivec4(int(uc - width/2.0 + 0.5),
                int(vc - height/2.0 + 0.5), int(width), int(height));
        glm::vec4 perspective = glm::vec4(
                float(2 * atan(height/2.f/(r * f /dy))/M_PI * 180),
                float(width)/height * (dx/dy),
                near_clip,
                far_clip);
        return std::make_pair(viewport, perspective);
    }


    glm::mat4 perspective_matrix(float fov, float aspect, float znear, float zfar)
    {
        glm::mat4 perp = glm::perspective(fov, aspect, znear, zfar);
        return perp;
    }

    glm::mat3 gl2cv(
            glm::ivec4 viewport,
            float fovy,
            float aspect,
            float r = 1
            )
     {
        float uc = viewport[2] / 2.0 + viewport[0];
        float vc = viewport[3] / 2.0 + viewport[1];
        float fy = 1.0f/tan(fovy/ 180.0 * M_PI / 2.0) * viewport[3] /2.0 / r;
        float fx = fy / aspect / viewport[3] * viewport[2];

        glm::mat3 intrinsic = glm::mat3(
                fx, 0, uc,
                0, fy, vc,
                0, 0, 1);
        return intrinsic;
    }
};
#endif
