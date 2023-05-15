//ͷ�ļ�Ҫ��
#include <cmath>
#include "vector2.h"

//�ӷ�
vector2 operator +(vector2 x, vector2 y) { 
	return vector2(x.x + y.x, x.y + y.y ); 
}

//����
vector2 operator -(vector2 x, vector2 y) {
	return vector2(x.x - y.x, x.y - y.y);
}

// �˷�
vector2 operator *(vector2 x, vector2 y) {
	return vector2(x.x * y.x - x.y * y.y, x.y * y.x + x.x * y.y);
}

// �˷�
vector2 operator *(vector2 y, float x) {
	return vector2(x*y.x, x*y.y);
}

vector2 operator *(float x, vector2 y) {
	return vector2(x * y.x, x * y.y);
}

//���
long long cross(vector2 x, vector2 y) { return x.y * y.x - x.x * y.y; }

//������ ���
long long dot(vector2 x, vector2 y) { return x.x * y.x + x.y * y.y; }

//�����������
long long dv(long long a, long long b) {//ע������������ 
	return b < 0 ? dv(-a, -b)
		: (a < 0 ? -dv(-a, b)
			: (a + b / 2) / b);
}

//ģ��ƽ��
long long len(vector2 x) { return x.x * x.x + x.y * x.y; }

//ģ��
long long dis(vector2 x) { return sqrt(x.x * x.x + x.y * x.y); }

//��������
vector2 operator /(vector2 x, vector2 y) {
	long long l = len(y);
	return vector2(dv(dot(x, y), l), dv(cross(x, y), l));
}

//����Ĥ
vector2 operator %(vector2 x, vector2 y) { return x - ((x / y) * y); }

//����GCD 
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
