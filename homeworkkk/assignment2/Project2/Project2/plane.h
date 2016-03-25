#ifndef _PLANE_H
#define _PLANE_H

#include "object3d.h"

class Plane: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	Plane(Vec3f _normal, float _offset, Vec3f _color):Object3D(_color)
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