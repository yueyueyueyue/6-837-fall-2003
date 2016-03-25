#ifndef _GROUP_H
#define _GROUP_H

#include "object3d.h"


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