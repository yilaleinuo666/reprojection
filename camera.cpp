#include "camera.h"

Pixel project(const Camera& cam, const Point3D& pw)
{
    // 外参：世界 -> 相机
    double Xc = cam.R[0][0]*pw.x + cam.R[0][1]*pw.y + cam.R[0][2]*pw.z + cam.t[0];
    double Yc = cam.R[1][0]*pw.x + cam.R[1][1]*pw.y + cam.R[1][2]*pw.z + cam.t[1];
    double Zc = cam.R[2][0]*pw.x + cam.R[2][1]*pw.y + cam.R[2][2]*pw.z + cam.t[2];

    // 归一化
    double x = Xc / Zc;
    double y = Yc / Zc;

    // 内参：相机 -> 像素
    Pixel px;
    px.u = cam.fx * x + cam.cx;
    px.v = cam.fy * y + cam.cy;
    return px;
}