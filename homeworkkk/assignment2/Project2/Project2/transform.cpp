#include "transform.h"

bool Transform::intersect(const Ray &ray, Hit &h, float tmin)
{
	//对ray进行变换
	Vec3f dir = ray.getDirection();
	T_1.TransformDirection(dir);//dir = T_1*dir
	Vec3f ori = ray.getOrigin();
	T_1.Transform(ori);//ori = T_1*ori
	                 //用齐次方程计算transform，得到的第四维是没意义的，不用管。
	                 //只有计算投影的时候，第四维才是有用的
	Ray T_ray(dir, ori);
	if(pObj3d->intersect(T_ray, h, tmin)){
		//改变normal，因为变换了，normal也变换了
		h.normalTransform(T);

		return 1;
	}else{
		return 0;
	}	
}