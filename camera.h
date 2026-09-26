#pragma once

// 3D 点
struct Point3D {
    double x, y, z;
};

// 像素坐标
struct Pixel {
    double u, v;
};

// 相机：内参 + 外参
struct Camera {
    double fx, fy, cx, cy;    // 内参
    double R[3][3];           // 旋转矩阵
    double t[3];              // 平移向量
};

// 世界点 -> 像素坐标
Pixel project(const Camera& cam, const Point3D& pw);