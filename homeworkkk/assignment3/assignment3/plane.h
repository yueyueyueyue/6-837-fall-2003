#ifndef _PLANE_H
#define _PLANE_H

#include "object3d.h"
#include "material.h"

class Plane: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	Plane(Vec3f _normal, float _offset, PhongMaterial _mtr):Object3D(_mtr)
	{
		normal = _normal;
		normal.Normalize();
		offset = _offset;
	}
	~Plane(){}
	//inplemented in CPP
	virtual bool intersect(const Ray &r, Hit &h, float tmin);
	
private:
	Vec3f normal;
	float offset;
};


#endif