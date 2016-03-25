#include "transform.h"

bool Transform::intersect(const Ray &ray, Hit &h, float tmin)
{
	//��ray���б任
	Vec3f dir = ray.getDirection();
	T_1.TransformDirection(dir);//dir = T_1*dir
	Vec3f ori = ray.getOrigin();
	T_1.Transform(ori);//ori = T_1*ori
	                 //����η��̼���transform���õ��ĵ���ά��û����ģ����ùܡ�
	                 //ֻ�м���ͶӰ��ʱ�򣬵���ά�������õ�
	Ray T_ray(dir, ori);
	if(pObj3d->intersect(T_ray, h, tmin)){
		//�ı�normal����Ϊ�任�ˣ�normalҲ�任��
		h.normalTransform(T);

		return 1;
	}else{
		return 0;
	}	
}