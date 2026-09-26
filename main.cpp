#include <iostream>
#include "camera.h"
using namespace std;

int main()
{
    Camera cam;
    Point3D pw;
    Pixel obs;

    cout << "请输入世界点 x y z: ";
    cin >> pw.x >> pw.y >> pw.z;

    cout << "请输入旋转矩阵 R (9 个数，按行): ";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> cam.R[i][j];

    cout << "请输入平移向量 t (3 个数): ";
    cin >> cam.t[0] >> cam.t[1] >> cam.t[2];

    cout << "请输入内参 fx fy cx cy: ";
    cin >> cam.fx >> cam.fy >> cam.cx >> cam.cy;

    cout << "请输入观测点 u v: ";
    cin >> obs.u >> obs.v;

    Pixel px;
    int ret = project(cam, pw, px);

    if (ret != 0) {
        cout << "非正深度，无法投影" << endl;
        return 0;
    }

    cout << "重投影像素坐标: (" << px.u << ", " << px.v << ")" << endl;
    cout << "像素欧氏距离平方: " << pixelDistanceSquared(px, obs) << endl;

    return 0;
}