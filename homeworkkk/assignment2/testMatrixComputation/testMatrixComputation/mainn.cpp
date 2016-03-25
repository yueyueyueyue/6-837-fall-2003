#include "matrix.h"
#include "vectors.h"
#include <iostream>
using namespace std;
int main()
{
	Vec3f v3;
	v3.Set(1,2,3);
	Matrix M;
	M.Set(0,0,1);M.Set(0,1,2);M.Set(0,2,3);M.Set(0,3,4);
	M.Set(1,0,5);M.Set(1,1,6);M.Set(1,2,7);M.Set(1,3,8);
	M.Set(2,0,9);M.Set(2,1,10);M.Set(2,2,11);M.Set(2,3,12);
	M.Set(3,0,0);M.Set(3,1,0);M.Set(3,2,0);M.Set(3,3,1);
	return 0;
}