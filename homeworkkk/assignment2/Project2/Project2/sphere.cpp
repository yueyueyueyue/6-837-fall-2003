#include "sphere.h"
bool Sphere::intersect(const Ray &r, Hit &h, float tmin)
{
	//ֱ�߷��� P = t*D + R    ��
	//Բ����  ||P||= raduis   ��
	//���ٴ����, �ɵ�˵�����(��������ʣ�������)�����t^2+2RDt+R^2-r^2=0
	//��t = -RD��sqrt(RD^2-R^2+r^2)
	//ѡ�����Ͻ����Ǹ���t = -RD-sqrt(RD^2-R^2+r^2)
	Vec3f D = r.getDirection();
	Vec3f R = r.getOrigin()-center;


	float R2 = R.Dot3(R);
	float RD = R.Dot3(D);
	
	float b2_4ac = RD*RD-R2+radius*radius;//R2 RD RDRD��Щ��ʵ���Դ���ray������㷨�о��Գ�������ΪҪ
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