#include <iostream>
#include "camera.h"
using namespace std;

int main()
{
    Camera cam;
    Point3D pw;

    // 1. 世界点
    cout << "请输入世界点 x y z: ";
    cin >> pw.x >> pw.y >> pw.z;

    // 2. 旋转矩阵 R (9 个数)
    cout << "请输入旋转矩阵 R (9 个数，按行): ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cam.R[i][j];
        }
    }

    // 3. 平移向量 t (3 个数)
    cout << "请输入平移向量 t (3 个数): ";
    cin >> cam.t[0] >> cam.t[1] >> cam.t[2];

    // 4. 内参
    cout << "请输入内参 fx fy cx cy: ";
    cin >> cam.fx >> cam.fy >> cam.cx >> cam.cy;

    // 5. 调用投影函数
    Pixel px = project(cam, pw);

    // 6. 输出
    cout << "重投影坐标: (" << px.u << ", " << px.v << ")" << endl;

    return 0;
}