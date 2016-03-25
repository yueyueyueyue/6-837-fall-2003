#include "camera.h"
#include "vectors.h"

Ray OrthographicCamera::generateRay(Vec2f point)
{
	//对point点，产生一个Ray
	Vec3f origin;
	origin = center + up*size*(point.y()-0.5) + horizontal*size*(point.x()-0.5);

	
	return Ray(direction, origin);
}