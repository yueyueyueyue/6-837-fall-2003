#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "object3d.h"
#include "matrix.h"
class Transform: public Object3D
{
	public:
	//CONSTRUCT & DESTRUCTOR
	Transform(Matrix T, Object3D *pObj3d):
		T(T), pObj3d(pObj3d)
	{
		T.Inverse(T_1);//T_1 = inverse(T)
	}
	~Transform(){}
	//inplemented in CPP
	virtual bool intersect(const Ray &r, Hit &h, float tmin);
	
private:
	Matrix T;
	Matrix T_1;
	Object3D *pObj3d;
};

#endif