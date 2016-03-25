#include "triangle.h"
Eigen::Vector3f Triangle::vec3f2EigenVector(const Vec3f &v)
{
	float a,b,c;
	v.Get(a,b,c);
	return Eigen::Vector3f(a,b,c);
	
}

bool Triangle::intersect(const Ray &r, Hit &h, float tmin)
{
	//ֱ�߷���     P = t*D + R                  ��
	//����ƽ�淽�� P = A + AB*beta + AC*gamma   ��
	//���ٴ����, 
	//��[D AB AC][t -beta -gamma]'= A - R
	//����beta+gamma<=1, beta>=0, gamma>=0 

	//���ƽ�У���ô�����
	float normalDotDir=r.getDirection().Dot3(normal);
	if(abs(normalDotDir)<0.0001)return 0;

	//�����β������˻�����������Ϊ�������ݱ�֤���
	float t, beta, gamma;
	Eigen::Matrix3f M;
	Eigen::Vector3f x;//Mx=b
	Eigen::Vector3f EigenD,EigenAB,EigenAC,EigenA_R;
	EigenD  = vec3f2EigenVector(r.getDirection());
	EigenAB = vec3f2EigenVector(AB);
	EigenAC = vec3f2EigenVector(AC);
	EigenA_R = vec3f2EigenVector(A-r.getOrigin());
	M <<EigenD,EigenAB,EigenAC;
	//���[D AB AC][t -beta -gamma]'= A-R
	//Mx=A-R
	x = M.colPivHouseholderQr().solve(EigenA_R);
	t = x(0,0);beta=-x(1,0);gamma=-x(2,0);

	//��������������beta+gamma<=1, beta>=0, gamma>=0, t>tmin
	if(beta+gamma>1)return 0;//beta+gamma<=1
	if(beta<0)return 0;//beta>=0
	if(gamma<0)return 0;//gamma>=0
	if(t<=tmin)return 0;//t>tmin
	
	if(t<h.getT())
	{
		if(normalDotDir<0)
		    h.set(t, &color, normal, r);
		else
			//h.set(t, &color, -1*normal, r);
			return 0;
	}
	return 1;
}