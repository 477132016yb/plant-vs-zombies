#pragma once

//头文件要求
#include <cmath>

class vector2 {
public:
    vector2()=default;
    ~vector2()=default;
	vector2(float x,float y) :x(x), y(y) {}
    vector2(vector2&vec);
	float x=0, y=0;
public:
    vector2 operator +(const vector2& vec)const;//加法
    vector2 operator -(const vector2& vec)const;//减法
    void operator+=(const vector2& vec);
    void operator-=(const vector2& vec);
    vector2 operator *(const vector2& vec)const;//乘法
    vector2 operator *(float val)const;
    friend vector2 operator*(float val, const vector2&vec);
    static float cross(const vector2 &x, const vector2 &y);//叉积
    static float dot(const vector2 &x, const vector2 &y);//点积
    static float dv(float a,float b);//四舍五入除法
    [[nodiscard]] float len() const;//模长平方
    [[nodiscard]] float dis() const;//模长
    vector2 operator /(const vector2 &vec) const;//向量除法
    vector2 operator %(const vector2 &vec) const;//向量膜
    [[nodiscard]] vector2 gcd(const vector2 &vec) const;//向量GCD
    static vector2 calcBezierPoint(float t, vector2 p0, vector2 p1, vector2 p2, vector2 p3);
    [[nodiscard]] vector2 normalize() const;
};













