#ifndef _HIT_H
#define _HIT_H

#include "vectors.h"
#include "light.h"
#include "matrix.h"
#include "material.h"

// ====================================================================
// ====================================================================

class Hit {
  
public:

  // CONSTRUCTOR & DESTRUCTOR
  Hit() { pMaterial = NULL; }
  Hit(float _t, Material *m, Vec3f n) { 
    t = _t; pMaterial = m; normal = n; }
  Hit(const Hit &h) { 
    t = h.t; 
    pMaterial = h.pMaterial; 
    normal = h.normal; 
    intersectionPoint = h.intersectionPoint; }
  ~Hit() {}

  // ACCESSORS
  float getT() const { return t; }
  Material* getMaterialPoint() const { return pMaterial; }
  Vec3f getNormal() const { return normal; }
  Vec3f getIntersectionPoint() const { return intersectionPoint; }
  
  // MODIFIER
  void set(float _t, Material *m, Vec3f n, const Ray &ray) {
    t = _t; pMaterial = m; normal = n; 
    intersectionPoint = ray.pointAtParameter(t); }
  void normalTransform(Matrix T)
  {
	  T.Inverse();
	  T.Transpose();
	  T.TransformDirection(normal);
	  normal.Normalize();

  }

private: 

  // REPRESENTATION
  float t;
  Material *pMaterial;//应为有多种material model所以这里用抽象类
  Vec3f normal;
  Vec3f intersectionPoint;

};

inline ostream &operator<<(ostream &os, const Hit &h) {
  os << "Hit <" <<h.getT()<<", "<<h.getNormal()<<">";
  return os;
}
// ====================================================================
// ====================================================================

#endif
