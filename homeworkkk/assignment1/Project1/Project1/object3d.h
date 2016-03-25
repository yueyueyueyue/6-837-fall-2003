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

class Sphere: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	Sphere(Vec3f _center, float _radius, Vec3f _color):Object3D(_color)
	{
		center = _center;
		radius = _radius;
	}
	Sphere(const Sphere &s)
	{
		center = s.center;
		radius = s.radius;
		color  = s.color;
	}
	~Sphere(){}
	//inplemented in CPP
	virtual bool intersect(const Ray &r, Hit &h, float tmin);
	
private:
	Vec3f center;
	float radius;
};

class Group: public Object3D
{
public:
	//CONSTRUCT & DESTRUCT
	Group()
	{
		item_up_num = 10;
		item_num = 0;
		items = new Object3D*[item_up_num];
	}
	Group(int num)
	{
		item_up_num = num;
		item_num = 0;
		items = new Object3D*[item_up_num];
	}
	~Group(){}

	virtual bool intersect(const Ray &r, Hit &h, float tmin);

	//void addObject(int index, Object3D *obj);
	void addObject(Object3D *obj);

private:
	int item_num;
	Object3D **items;
	int item_up_num;

};

#endif