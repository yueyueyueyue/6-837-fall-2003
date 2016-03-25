#ifndef _OBJECT3D_H
#define _OBJECT3D_H
//#include <vector>
//using namespace std;

class Object3D
{
public:

	//CONSTRUCT & DESTRUCTOR 
	Object3D(){}
	Object3D(int clr)
	{
		color = clr;
	}
	Object3D(const Object3D &obj)
	{
		color = obj.color;
	}
	~Object3D(){}

	//METHOD
	virtual void intersect() = 0;


protected:
	int color;

};

class Sphere: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	Sphere(int _center, int _radius, int _color):Object3D(_color)
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

	//inplemented in CPP
	virtual void intersect();

private:
	int center;
	int radius;
};

class Triangle: public Object3D
{
public:
	//CONSTRUCT & DESTRUCTOR
	Triangle(int _side, int _color):Object3D(_color)
	{
		side = _side;
	}

	//inplemented in CPP
	virtual void intersect();

private:
	int side;
};

class Group: public Object3D
{
public:
	//CONSTRUCT & DESTRUCT
	Group()
	{
		item_up_num = 10;
		items = new Object3D*[item_up_num];
		//items = vector<Object3D*>(item_up_num);
		item_num = 0;
	}
	~Group(){delete[] items;}

	void addObject(Object3D *obj);
	virtual	void intersect();
	int getItem_num(){return item_num;}
private:
	int item_num;
	Object3D **items;
	int item_up_num;

};

#endif