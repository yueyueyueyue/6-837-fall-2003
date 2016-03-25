#include "scene_parser.h"
#include "vectors.h"

class RayTracer
{
public:
	RayTracer(SceneParser *s, int max_bounces, float min_weight)
	{

	}
	~RayTracer(){}

	//given a ray, computes the color seen from the origin along the direction(recursively)
	//bounce means recursion depth
	//weight
	Vec3f traceRay(Ray &ray, float tmin, int bounces, 
		float weight, float indexOfRefraction, Hit &hit)const;
};