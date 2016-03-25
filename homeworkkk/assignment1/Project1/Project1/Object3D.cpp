#include "Object3D.h"
#include "hit.h"
#include "ray.h"

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

bool Sphere::intersect(const Ray &r, Hit &h, float tmin)
{
	//ֱ�߷��� P = t*D + R    ��
	//Բ����  ||P||= raduis   ��
	//���ٴ����, �ɵ�˵�����(��������ʣ�������)�����t^2+2RDt+R^2-r^2=0
	//��t = -RD��sqrt(RD^2-R^2+r^2)
	//ѡ�����Ͻ����Ǹ���t = -RD-sqrt(RD^2-R^2+r^2)
	Vec3f D = r.getDirection();
	Vec3f R = r.getOrigin()-center;


	float R2 = R.Dot3(R);
	float RD = R.Dot3(D);
	
	float b2_4ac = RD*RD-R2+radius*radius;//R2 RD RDRD��Щ��ʵ���Դ���ray������㷨�о��Գ�������ΪҪ
	if(b2_4ac<0)return 0;
	float t;
	t = -RD - sqrt(b2_4ac);
	if(t<0){
		t = -RD + sqrt(b2_4ac);
		if(t < 0)return 0;
	}
	if(t<h.getT())
	{
		h.set(t, &color, r);
	}

	return 1;
}