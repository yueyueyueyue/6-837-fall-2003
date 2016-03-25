#include "sphere.h"
bool Sphere::intersect(const Ray &r, Hit &h, float tmin)
{
	//直线方程 P = t*D + R    ①
	//圆方程  ||P||= raduis   ②
	//将①带入②, 由点乘的性质(满足分配率，交换律)，求得t^2+2RDt+R^2-r^2=0
	//得t = -RD±sqrt(RD^2-R^2+r^2)
	//选择距离较近的那个点t = -RD-sqrt(RD^2-R^2+r^2)
	Vec3f D = r.getDirection();
	Vec3f R = r.getOrigin()-center;


	float R2 = R.Dot3(R);
	float RD = R.Dot3(D);
	
	float b2_4ac = RD*RD-R2+radius*radius;//R2 RD RDRD这些其实可以存在ray里，但是算法研究以程序清晰为要
	if(b2_4ac<0)return 0;
	float t;
	t = -RD - sqrt(b2_4ac);
	if(t<tmin){
		t = -RD + sqrt(b2_4ac);
		if(t < tmin)return 0;
	}

	Vec3f normal;
	if(t<h.getT())
	{
		normal = r.pointAtParameter(t) - center;
		normal.Normalize();

		h.set(t, &color, normal, r);
	}

	return 1;
}