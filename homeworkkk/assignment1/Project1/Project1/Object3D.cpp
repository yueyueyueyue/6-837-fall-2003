#include "Object3D.h"
#include "hit.h"
#include "ray.h"

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

bool Sphere::intersect(const Ray &r, Hit &h, float tmin)
{
	//直线方程 P = t*D + R    ①
	//圆方程  ||P||= raduis   ②
	//将①带入②, 由点乘的性质(满足分配率，交换律)，求得t^2+2RDt+R^2-r^2=0
	//得t = -RD±sqrt(RD^2-R^2+r^2)
	//选择距离较近的那个点t = -RD-sqrt(RD^2-R^2+r^2)
	Vec3f D = r.getDirection();
	Vec3f R = r.getOrigin()-center;


	float R2 = R.Dot3(R);
	float RD = R.Dot3(D);
	
	float b2_4ac = RD*RD-R2+radius*radius;//R2 RD RDRD这些其实可以存在ray里，但是算法研究以程序清晰为要
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