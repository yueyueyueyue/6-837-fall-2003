#include "test_obj.h"
#include <iostream>
#include <limits>
using namespace std;
Sphere testt(){return Sphere(1,1,1);}
int main(int argc, char** argv)
{	
	Sphere s0 = Sphere(0,5,3);
	Sphere s1 = Sphere(1,5,3);	
	Sphere s2 = Sphere(2,5,3);	
	Sphere s3 = Sphere(3,5,3);	
	Sphere s4 = Sphere(4,5,3);	
	Sphere s5 = Sphere(5,5,3);	
	Sphere s6 = Sphere(6,5,3);	
	Sphere s7 = Sphere(7,5,3);	
	Sphere s8 = Sphere(8,5,3);	
	Sphere s9 = Sphere(9,5,3);
	Triangle t0 = Triangle(0,3);
	Triangle t1 = Triangle(1,3);	
	Triangle t2 = Triangle(2,3);	
	Triangle t3 = Triangle(3,3);	
	Triangle t4 = Triangle(4,3);	
	Triangle t5 = Triangle(5,3);	
	Triangle t6 = Triangle(6,3);	
	Triangle t7 = Triangle(7,3);	
	Triangle t8 = Triangle(8,3);	
	Triangle t9 = Triangle(9,3);

	Group group;
	
	group.addObject(&s0);
	group.addObject(&s1);
	group.addObject(&s2);
	group.addObject(&s3);
	group.addObject(&s4);
	group.addObject(&s5);
	group.addObject(&s6);
	group.addObject(&s7);
	group.addObject(&s8);
	group.addObject(&s9);
	group.addObject(&t0);
	group.addObject(&t1);
	group.addObject(&t2);
	group.addObject(&t3);
	group.addObject(&t4);
	group.addObject(&t5);
	group.addObject(&t6);
	group.addObject(&t7);
	group.addObject(&t8);
	group.addObject(&t9);

	group.intersect();
	testt().intersect();
	Object3D *s=new Sphere(100,2,3);
	s->intersect();
	
	cout<<"numeric_limits<float>::max()="<<numeric_limits<float>::max()<<endl;
	cout<<"numeric_limits<float>::min()="<<numeric_limits<float>::min()<<endl;
	cout<<"numeric_limits<float>::lowest()="<<numeric_limits<float>::lowest()<<endl;

	system("pause");
	return 0;
}