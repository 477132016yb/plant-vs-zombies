#pragma once

//ͷ�ļ�Ҫ��
#include <cmath>

class vector2 {
public:
    vector2()=default;
    ~vector2()=default;
	vector2(float x,float y) :x(x), y(y) {}
    vector2(vector2&vec);
	float x=0, y=0;
public:
    vector2 operator +(const vector2& vec)const;//�ӷ�
    vector2 operator -(const vector2& vec)const;//����
    void operator+=(const vector2& vec);
    void operator-=(const vector2& vec);
    vector2 operator *(const vector2& vec)const;//�˷�
    vector2 operator *(float val)const;
    friend vector2 operator*(float val, const vector2&vec);
    static float cross(const vector2 &x, const vector2 &y);//���
    static float dot(const vector2 &x, const vector2 &y);//���
    static float dv(float a,float b);//�����������
    [[nodiscard]] float len() const;//ģ��ƽ��
    [[nodiscard]] float dis() const;//ģ��
    vector2 operator /(const vector2 &vec) const;//��������
    vector2 operator %(const vector2 &vec) const;//����Ĥ
    [[nodiscard]] vector2 gcd(const vector2 &vec) const;//����GCD
    static vector2 calcBezierPoint(float t, vector2 p0, vector2 p1, vector2 p2, vector2 p3);
    [[nodiscard]] vector2 normalize() const;
};













