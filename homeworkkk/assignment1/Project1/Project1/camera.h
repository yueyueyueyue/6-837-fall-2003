#ifndef _CAMERA_H
#define _CAMERA_H

#include "ray.h"
#include "hit.h"
#include "vectors.h"
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
		Vec3f::Cross3(horizontal, up, direction);//horizontal=up×direction
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

#endif