#include "group.h"
void Group::addObject(Object3D *obj)
{
	if(item_num==item_up_num)//原来的已经满了,再放就要放不下了
	{
		item_up_num *=2;
		
		//items数组放不下了，要括容
		Object3D **_items = new Object3D*[item_up_num];

		memcpy(_items, items, item_num*sizeof(Object3D*));

		delete[] items;
		items = _items;
	}


	//更新
	//printf("%d %d\n",item_num,item_up_num);
	item_num++;
	items[item_num-1] = obj;
}

bool Group::intersect(const Ray &r, Hit &h, float tmin)
{
	bool hitted = 0;
	//loop through all the instances, calling their intersection methods
	for(int i=0;i!=item_num;i++)
	{
		if(items[i]->intersect(r, h, tmin))//不停对h进行更新
		{
			hitted = 1;
		}
	}
	return hitted;
}