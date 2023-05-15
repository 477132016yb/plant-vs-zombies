//头文件要求
#include <cmath>
#include "vector2.h"

//加法
vector2 operator +(vector2 x, vector2 y) { 
	return vector2(x.x + y.x, x.y + y.y ); 
}

//减法
vector2 operator -(vector2 x, vector2 y) {
	return vector2(x.x - y.x, x.y - y.y);
}

// 乘法
vector2 operator *(vector2 x, vector2 y) {
	return vector2(x.x * y.x - x.y * y.y, x.y * y.x + x.x * y.y);
}

// 乘法
vector2 operator *(vector2 y, float x) {
	return vector2(x*y.x, x*y.y);
}

vector2 operator *(float x, vector2 y) {
	return vector2(x * y.x, x * y.y);
}

//叉积
long long cross(vector2 x, vector2 y) { return x.y * y.x - x.x * y.y; }

//数量积 点积
long long dot(vector2 x, vector2 y) { return x.x * y.x + x.y * y.y; }

//四舍五入除法
long long dv(long long a, long long b) {//注意重名！！！ 
	return b < 0 ? dv(-a, -b)
		: (a < 0 ? -dv(-a, b)
			: (a + b / 2) / b);
}

//模长平方
long long len(vector2 x) { return x.x * x.x + x.y * x.y; }

//模长
long long dis(vector2 x) { return sqrt(x.x * x.x + x.y * x.y); }

//向量除法
vector2 operator /(vector2 x, vector2 y) {
	long long l = len(y);
	return vector2(dv(dot(x, y), l), dv(cross(x, y), l));
}

//向量膜
vector2 operator %(vector2 x, vector2 y) { return x - ((x / y) * y); }

//向量GCD 
vector2 gcd(vector2 x, vector2 y) { return len(y) ? gcd(y, x % y) : x; }


vector2 calcBezierPoint(float t, vector2 p0, vector2 p1, vector2 p2, vector2 p3) {
	float u = 1 - t;
	float tt = t * t;
	float uu = u * u;
	float uuu = uu * u;
	float ttt = tt * t;

	vector2 p = uuu * p0;
	p = p + 3 * uu * t * p1;
	p = p + 3 * u * tt * p2;
	p = p + ttt * p3;

	return p;
}
