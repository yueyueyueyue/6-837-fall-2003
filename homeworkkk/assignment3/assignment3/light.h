#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "vectors.h"

// ====================================================================
// DirectionalLight:
//  Vec3f derection
//  Vec3f color
//  void getIllumination(const Vec3f &p, Vec3f &dir, Vec3f &col);
// ====================================================================

class Light {

public:

  // CONSTRUCTOR & DESTRUCTOR
  Light() {}
  virtual ~Light() {}

  // VIRTUAL METHOD
  virtual void getIllumination (const Vec3f &p, Vec3f &dir, Vec3f &col) const = 0;

};

// ====================================================================
// ====================================================================

class DirectionalLight : public Light {

public:

  // CONSTRUCTOR & DESTRUCTOR
  DirectionalLight() { 
    direction = Vec3f(0,0,0);
    color = Vec3f(1,1,1); }
  DirectionalLight(const Vec3f &d, const Vec3f &c) {
    direction = d; direction.Normalize();
    color = c; }
  virtual ~DirectionalLight() {}

  // VIRTUAL METHOD
  void getIllumination (const Vec3f &p, Vec3f &dir, Vec3f &col) const {
    // the direction to the light is the opposite of the
    // direction of the directional light source
    dir = direction * (-1.0f);
    col = color; }

private:

  // REPRESENTATION
  Vec3f direction;
  Vec3f color;

};

// ====================================================================
// ====================================================================
class PointLight : public Light {

public:

  // CONSTRUCTOR & DESTRUCTOR
  PointLight() {
    position = Vec3f(0,0,0);
    color = Vec3f(1,1,1); 
	attenuation = Vec3f(0,0,0);
  }
  PointLight(const Vec3f &p, const Vec3f &c, float _attenuation) {
    position = p; 
    color = c;
	attenuation = _attenuation;
  }
  virtual ~PointLight() {}

  // VIRTUAL METHOD
  // Get L
  void getIllumination (const Vec3f &p, Vec3f &dir, Vec3f &col) const {
    // the direction to the light is the opposite of the
    // direction of the directional light source
	dir = position - p;
	dir = dir.Normalise();
    col = color; }
	
private:
    Vec3f position;
    Vec3f color;
    Vec3f attenuation;
}


#endif
