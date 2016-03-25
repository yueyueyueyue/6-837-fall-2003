#ifndef _OBJECT3D_H
#define _OBJECT3D_H

#include "ray.h"
#include "hit.h"
#include "material.h"
#include "vectors.h"
#include <vector>
using namespace std;

class Object3D
{
public:

	//CONSTRUCT & DESTRUCTOR 
	Object3D(){}
	Object3D(PhongMaterial mtr)
	{
		material = PhongMaterial(mtr);
	}
	Object3D(const Object3D &obj)
	{
		material = obj.material;
	}
	~Object3D(){}

	//METHOD
	virtual bool intersect(const Ray &r, Hit &h, float tmin) = 0;


protected:
	PhongMaterial material;

};



#endif