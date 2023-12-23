//头文件要求
#include <cmath>
#include "vector2.h"

vector2 vector2::operator+(const vector2 &vec) const {
    return {x+vec.x,y+vec.y};
}

vector2 vector2::operator-(const vector2 &vec) const {
    return {x-vec.x,y-vec.y};
}

void vector2::operator+=(const vector2 &vec) {
    x+=vec.x,y+=vec.y;
}

void vector2::operator-=(const vector2 &vec) {
    x-=vec.x,y-=vec.y;
}

vector2 vector2::operator*(float val) const {
    return {x*val,y*val};
}

vector2 vector2::operator*(const vector2 &vec) const {
    return {x*vec.x-y*vec.y,x*vec.x+y*vec.y};
}

vector2 operator*(float val,const vector2 &vec) {
    return {vec.x*val,vec.y*val};
}

float vector2::cross(const vector2 &x, const vector2 &y) {
    return x.y * y.x - x.x * y.y;
}

float vector2::dot(const vector2 &x, const vector2 &y) {
    return x.x * y.x + x.y * y.y;
}

float vector2::dv(float a, float b) {
    if (b < 0) {
        return dv(-a, -b);
    } else {
        return a < 0 ? -dv(-a, b)
                     : (a + b / 2) / b;
    }
}

float vector2::len() const {
    return x*x+y*y;
}

float vector2::dis() const {
    return std::sqrt(len());
}

vector2 vector2::operator/(const vector2 &vec) const{
    float l = vec.len();
    vector2 t(x,y);
    return {dv(dot(t, vec), l), dv(cross(t, vec), l)};
}

vector2 vector2::operator%(const vector2 &vec) const {
    vector2 t1(x,y);
    vector2 t2=(t1 / vec) * vec;
    return t1 - t2;
}

vector2 vector2::gcd(const vector2 &vec) const {
    vector2 t1(x,y);
    return (bool)vec.len() ? t1 : t1;
}

vector2 vector2::calcBezierPoint(float t, vector2 p0, vector2 p1, vector2 p2, vector2 p3) {
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    vector2 p = uuu * p0;
    p += 3 * uu * t * p1;
    p += 3 * u * tt * p2;
    p +=ttt * p3;
    return p;
}

vector2 vector2::normalize() const {
    float l=dis();
    if(l==0){
        return {0,0};
    }
    return {x/l,y/l};
}

vector2::vector2(vector2 &vec) {
    x=vec.x;
    y=vec.y;
}

