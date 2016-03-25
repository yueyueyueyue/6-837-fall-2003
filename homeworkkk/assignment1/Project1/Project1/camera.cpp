#include "camera.h"
#include "vectors.h"

Ray OrthographicCamera::generateRay(Vec2f point)
{
	//��point�㣬����һ��Ray
	Vec3f origin;
	origin = center + up*size*(point.y()-0.5) + horizontal*size*(point.x()-0.5);

	
	return Ray(direction, origin);
}