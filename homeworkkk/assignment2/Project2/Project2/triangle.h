#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "object3d.h"
#include <Eigen\Dense>

class Triangle: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	//一点a，加两边ab, ac定义一个三角形
	Triangle(Vec3f _a, Vec3f _b, Vec3f _c, Vec3f _color):Object3D(_color)
	{
		A = _a;
		AB = _b - _a;
		AC = _c - _a;
		Vec3f::Cross3(normal, AB, AC);
		normal.Normalize();
	}
	~Triangle(){}
	//inplemented in CPP
	virtual bool intersect(const Ray &r, Hit &h, float tmin);
	
private:
	Vec3f A;
	Vec3f AB;
	Vec3f AC;
	Vec3f normal;

	Eigen::Vector3f vec3f2EigenVector(const Vec3f &v);
};

#endif