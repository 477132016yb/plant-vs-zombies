#pragma once

//头文件要求
#include <cmath>

struct vector2 {
	vector2(int _x=0, int _y=0) :x(_x), y(_y) {}
	vector2(int* data) :x(data[0]), y(data[1]){}
	long long x, y;
};

//加法
vector2 operator +(vector2 x, vector2 y);

//减法
vector2 operator -(vector2 x, vector2 y);

// 乘法
vector2 operator *(vector2 x, vector2 y);
vector2 operator *(vector2, float);
vector2 operator *(float, vector2);

//叉积
long long cross(vector2 x, vector2 y);

//数量积 点积
long long dot(vector2 x, vector2 y);

//四舍五入除法
long long dv(long long a, long long b);


//模长平方
long long len(vector2 x);

//模长
long long dis(vector2 x);

//向量除法
vector2 operator /(vector2 x, vector2 y);

//向量膜
vector2 operator %(vector2 x, vector2 y);

//向量GCD 
vector2 gcd(vector2 x, vector2 y);

vector2 calcBezierPoint(float t, vector2 p0, vector2 p1, vector2 p2, vector2 p3);