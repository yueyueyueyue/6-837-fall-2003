#ifndef _MATERIAL_H
#define _MATERIAL_H
#include "vectors.h"
#include "hit.h"
#include "ray.h"

//存储了各种材质信息，对于视线信息和光线信息返回一个颜色
class Material
{
public:
	Material(){}
	Material(const Vec3f &diffuseColor,
			const Vec3f &transparencyColor,
			const Vec3f &reflectiveColor,
			float indexOfRefraction):
			diffuseColor(diffuseColor),
			transparencyColor(transparencyColor),
			reflectiveColor(reflectiveColor),
			indexOfRefraction(indexOfRefraction){}

	~Material(){}
	//
	virtual Vec3f shade(const Ray &ray, 
						const Hit &hit,
						const Vec3f &dirToLight,
						const Vec3f &lightColor)const=0;
						//函数名后跟const说明该函数不会改变对象的成员变量的值
	Vec3f getDiffuseColor(){return diffuseColor;}
	Vec3f getTransparencyColor(){return transparencyColor;}
	Vec3f getReflectiveColor(){return reflectiveColor;}

protected:
	//coefficient代表了对不同颜色的吸收率
	Vec3f diffuseColor;//diffuse coefficient
	Vec3f transparencyColor;//transparency coefficient
	Vec3f reflectiveColor;//reflection coefficient
	float indexOfRefraction;
};

class PhongMaterial:public Material
{
public:
	PhongMaterial(){}
	PhongMaterial(const Vec3f &_diffuseColor,
					const Vec3f &_specularColor,
					float _exponent,
					const Vec3f &_transparencyColor,
					const Vec3f &_reflectiveColor,
					float _indexOfRefraction )
	{
		diffuseColor=_diffuseColor;
		specularColor=_specularColor;
		exponent=_exponent;
		transparencyColor=_transparencyColor;
		reflectiveColor=_reflectiveColor;
		indexOfRefraction=_indexOfRefraction;
	}
					

	~PhongMaterial(){}

	virtual Vec3f shade(const Ray &ray, 
						const Hit &hit,
						const Vec3f &dirToLight,
						const Vec3f &lightColor)const;
	//函数名后跟const说明该函数不会改变对象的成员变量的值

	Vec3f getSpecularColor(){return specularColor;}

private:
	Vec3f specularColor;
	float exponent;
};


#endif