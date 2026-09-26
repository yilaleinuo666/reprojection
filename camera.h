#pragma once

struct Point3D { double x, y, z; };
struct Pixel   { double u, v; };

struct Camera {
    double fx, fy, cx, cy;
    double R[3][3];
    double t[3];
};

// 返回 0 = 成功，-1 = 非正深度
int project(const Camera& cam, const Point3D& pw, Pixel& out);

// 像素欧氏距离的平方
double pixelDistanceSquared(const Pixel& a, const Pixel& b);