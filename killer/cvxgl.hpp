#ifndef _CHAOJIWUDI_SUPER_PAIN_KILLER_BY_UU
#def _CHAOJIWUDI_SUPER_PAIN_KILLER_BY_UU
#include <glm/glm.hpp>

namespace cvxgl{
    void cv2gl(
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

        glm::vec4 viewport = glm::vec4(uc - width/2.0, vc - height/2.0, width, height);
        glm::perspective = glm::perspective(
                2 * atan(heigh/2.0/(r * f /dy))/M_PI * 180,
                float(width)/height* (dx/dy), near_clip, far_clip);
    }

    glm::mat3 gl2cv(
            glm::ivec4 viewport,
            float fovy,
            float aspect,
            float r = 1
            ){
        float uc = viewport[2] / 2.0 + viewport[0];
        float vc = viewport[3] / 2.0 + viewport[1];
        float fy = cot(fovy / 2.0) * height /2.0 / r;
        float fx = fy / (aspect * height / width);

        glm::intrinsic = glm::mat3(
                fx, 0, uc,
                0, fy, uc,
                0, 0, 1);
        return intrinsic;
    }
};
#endif


