#ifndef _CAMERA_H
#define _CAMERA_H

#include "ray.h"
#include "hit.h"
#include "vectors.h"
#include <math.h>
//每个相机包含的参数有:
//方向，size
class Camera
{
public:
	//CONSTRUCTOR AND DECONSTRUCTOR
	Camera(){}
	Camera(float size,Vec3f center):size(size),center(center){}
	~Camera(){}
	//为每个screen-space坐标产生一个ray
	virtual Ray generateRay(Vec2f point) = 0;

protected:
	float size;

	//center of the image
	Vec3f center;
};

class OrthographicCamera: public Camera
{
public:
	//CONSTRUCTOR AND DECONSTRUCTOR
	OrthographicCamera(){}
	OrthographicCamera(Vec3f ctr, Vec3f dir, Vec3f upp, float sizee)
	{
		size      = sizee;
		center    = ctr;
		dir.Normalize();
		direction = dir;
		upp.Normalize();
		up        = upp;
		Vec3f::Cross3(horizontal, direction, up);//horizontal=up×direction
	}

	//ray generation method
	virtual Ray generateRay(Vec2f point);

private:
	//one point and three vectors(normalized)

	

	//the projection direction
	Vec3f direction;
	//up vector
	Vec3f up;
	//horizontal vector
	Vec3f horizontal;
	//image size(one floating point)

	// The origin of the rays vary from (0,0)→(1,1)should be 
	//   center - up*size*(y-0.5) - horizontal*size*(x-0.5)

	//camera does not know the screen resolution


};


class PerspectiveCamera: public Camera
{
public:
	//CONSTRUCTOR AND DECONSTRUCTOR
	PerspectiveCamera(){}
	PerspectiveCamera(Vec3f ctr, Vec3f dir, Vec3f upp, float alpha)
	{
		//依旧认为成像面离视点距离为1
		height=width=sqrt(2/cos(alpha)-2);

		center    = ctr;
		dir.Normalize();
		direction = dir;
		upp.Normalize();
		up        = upp;
		Vec3f::Cross3(horizontal, direction, up);//horizontal=direction×up
	}

	//ray generation method
	virtual Ray generateRay(Vec2f point);
	Vec3f getDir()
	{return direction;}

private:
	//one point and three vectors(normalized)

	float height, width;

	//the projection direction
	Vec3f direction;
	//up vector
	Vec3f up;
	//horizontal vector
	Vec3f horizontal;

	// The origin of the rays vary from (0,0)→(1,1)should be 
	//   center - up*size*(y-0.5) - horizontal*size*(x-0.5)

	//camera does not know the screen resolution


};

#endif