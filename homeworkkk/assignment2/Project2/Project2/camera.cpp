#include "camera.h"
#include "vectors.h"

Ray OrthographicCamera::generateRay(Vec2f point)
{
	//��point�㣬����һ��Ray
	Vec3f origin;
	origin = center + up*size*(point.y()-0.5) + horizontal*size*(point.x()-0.5);

	
	return Ray(direction, origin);
} 

Ray PerspectiveCamera::generateRay(Vec2f point)
{
	//��point�㣬����һ��Ray
	Vec3f origin;
	origin = center+ direction + up*height*(point.y()-0.5) + horizontal*width*(point.x()-0.5);
	Vec3f raydir = origin - center;
	raydir.Normalize();
	
	return Ray(raydir, origin);
} 