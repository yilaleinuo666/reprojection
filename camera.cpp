#include "camera.h"

int project(const Camera& cam, const Point3D& pw, Pixel& out)
{
    double Xc = cam.R[0][0]*pw.x + cam.R[0][1]*pw.y + cam.R[0][2]*pw.z + cam.t[0];
    double Yc = cam.R[1][0]*pw.x + cam.R[1][1]*pw.y + cam.R[1][2]*pw.z + cam.t[1];
    double Zc = cam.R[2][0]*pw.x + cam.R[2][1]*pw.y + cam.R[2][2]*pw.z + cam.t[2];

    if (Zc <= 0.0) return -1;

    out.u = cam.fx * (Xc / Zc) + cam.cx;
    out.v = cam.fy * (Yc / Zc) + cam.cy;
    return 0;
}

double pixelDistanceSquared(const Pixel& a, const Pixel& b)
{
    double du = a.u - b.u;
    double dv = a.v - b.v;
    return du*du + dv*dv;
}