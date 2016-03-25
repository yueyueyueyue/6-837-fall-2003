#include "group.h"
void Group::addObject(Object3D *obj)
{
	if(item_num==item_up_num)//ԭ�����Ѿ�����,�ٷž�Ҫ�Ų�����
	{
		item_up_num *=2;
		
		//items����Ų����ˣ�Ҫ����
		Object3D **_items = new Object3D*[item_up_num];

		memcpy(_items, items, item_num*sizeof(Object3D*));

		delete[] items;
		items = _items;
	}


	//����
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
		if(items[i]->intersect(r, h, tmin))//��ͣ��h���и���
		{
			hitted = 1;
		}
	}
	return hitted;
}