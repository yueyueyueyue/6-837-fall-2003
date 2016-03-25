#ifndef _HIT_H
#define _HIT_H

#include "vectors.h"
#include "ray.h"

#define Material Vec3f

// ====================================================================
// ====================================================================

//t的意思是ray上的最近的交点
//store the info about the closest intersection point:
//1.ray parameter t
//2.material at the intersection(ex. color)

class Hit {
  
public:

  // CONSTRUCTOR & DESTRUCTOR
  Hit() { material = NULL; }
  //Hit(float _t, Material *m, Vec3f n) {
  Hit(float _t, Material *m) {
    //t = _t; material = m; normal = n; }
	  t = _t; material = m; }
  Hit(const Hit &h) { 
    t = h.t; 
    material = h.material; 
    //normal = h.normal; 
    intersectionPoint = h.intersectionPoint; }
  ~Hit() {}

  // ACCESSORS
  float getT() const { return t; }
  Material* getMaterial() const { return material; }
  //Vec3f getNormal() const { return normal; }
  Vec3f getIntersectionPoint() const { return intersectionPoint; }
  
  // MODIFIER
  //void set(float _t, Material *m, Vec3f n, const Ray &ray) {
  void set(float _t, Material *m, const Ray &ray) {
    t = _t; material = m; //normal = n; 
    intersectionPoint = ray.pointAtParameter(t); }

private: 

  // REPRESENTATION
  float t;
  Material *material;
  //Vec3f normal;
  Vec3f intersectionPoint;

};

//inline ostream &operator<<(ostream &os, const Hit &h) {
//  os << "Hit <" <<h.getT()<<", "<<h.getNormal()<<">";
//  return os;
//}
// ====================================================================
// ====================================================================

#endif
