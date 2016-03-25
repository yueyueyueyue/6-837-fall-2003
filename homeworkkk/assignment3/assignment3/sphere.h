#ifndef _SPHERE_H
#define _SPHERE_H

#include "object3d.h"

class Sphere: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	Sphere(Vec3f _center, float _radius, PhongMaterial _material):Object3D(_material)
	{
		center = _center;
		radius = _radius;
	}
	Sphere(const Sphere &s)
	{
		center = s.center;
		radius = s.radius;
		material  = s.material;
	}
	~Sphere(){}
	//inplemented in CPP
	virtual bool intersect(const Ray &r, Hit &h, float tmin);
	
private:
	Vec3f center;
	float radius;
};


#endif