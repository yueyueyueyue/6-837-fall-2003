#include "material.h"
#include "vectors.h"
Vec3f PhongMaterial::shade(const Ray &ray, 
						const Hit &hit,
						const Vec3f &dirToLight,
						const Vec3f &lightColor)const
{

	return Vec3f(0,0,0);
}