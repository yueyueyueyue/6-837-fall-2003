#include "plane.h"
bool Plane::intersect(const Ray &r, Hit &h, float tmin)
{
	//直线方程 P = t*D + R      ①
	//圆方程   N*X-offset=0     ②
	//将①带入②
	//得t = (-offset-N*R)/D*N

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
		if(ND<0)//ND小于零说明现在这个normal正面朝着视点 此处normal会影响到light source的打光
			h.set(t, &color, normal, r);
		else
			h.set(t, &color, -1*normal, r);
	}

	return 1;
}