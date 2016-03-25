#ifndef _MATERIAL_H
#define _MATERIAL_H
#include "vectors.h"
#include "hit.h"
#include "ray.h"

//�洢�˸��ֲ�����Ϣ������������Ϣ�͹�����Ϣ����һ����ɫ
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
						//���������const˵���ú�������ı����ĳ�Ա������ֵ
	Vec3f getDiffuseColor(){return diffuseColor;}
	Vec3f getTransparencyColor(){return transparencyColor;}
	Vec3f getReflectiveColor(){return reflectiveColor;}

protected:
	//coefficient�����˶Բ�ͬ��ɫ��������
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
	//���������const˵���ú�������ı����ĳ�Ա������ֵ

	Vec3f getSpecularColor(){return specularColor;}

private:
	Vec3f specularColor;
	float exponent;
};


#endif