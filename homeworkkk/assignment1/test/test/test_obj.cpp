#include "test_obj.h"
#include <iostream>
using namespace std;
void Sphere::intersect()
{
	cout<<"sphere intersect center:"<<center<<endl;
}

void Triangle::intersect()
{
	cout<<"triangle intersect side:"<<side<<endl;
}

void Group::addObject(Object3D *obj)
{
	if(item_num==item_up_num)//原来的已经满了
	{
		item_up_num *=2;
		
		//items数组放不下了，要括容
		Object3D **_items = new Object3D*[item_up_num];

		memcpy(_items, items, item_num*sizeof(Object3D*));

		delete[] items;
		items = _items;
	}
	//更新
	item_num++;
	items[item_num-1] = obj;
}

void Group::intersect()
{
	for(int i=0;i!=item_num;i++)
	{
		items[i]->intersect();
	}
}