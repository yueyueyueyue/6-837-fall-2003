#include "plane.h"
bool Plane::intersect(const Ray &r, Hit &h, float tmin)
{
	//ֱ�߷��� P = t*D + R      ��
	//Բ����   N*X-offset=0     ��
	//���ٴ����
	//��t = (-offset-N*R)/D*N

	Vec3f D = r.getDirection();
	Vec3f R = r.getOrigin();
	Vec3f N = normal;
	
	float ND = N.Dot3(D);
	if(abs(ND)<0.00001)return 0;

	float t;
	float NR = N.Dot3(R);
	
	t = (offset-NR)/ND;
	if(t < tmin)return 0;
	if(t<h.getT())
	{
		if(ND<0)//NDС����˵���������normal���泯���ӵ� �˴�normal��Ӱ�쵽light source�Ĵ��
			h.set(t, &color, normal, r);
		else
			h.set(t, &color, -1*normal, r);
	}

	return 1;
}