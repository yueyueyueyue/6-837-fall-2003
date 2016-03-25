#ifndef _OBJECT3D_H
#define _OBJECT3D_H

#include "ray.h"
#include "hit.h"
#include "vectors.h"
#include <vector>
using namespace std;

class Object3D
{
public:

	//CONSTRUCT & DESTRUCTOR 
	Object3D(){}
	Object3D(Vec3f clr)
	{
		color = Vec3f(clr);
	}
	Object3D(const Object3D &obj)
	{
		color = obj.color;
	}
	~Object3D(){}

	//METHOD
	virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;


protected:
	Vec3f color;

};



#endif