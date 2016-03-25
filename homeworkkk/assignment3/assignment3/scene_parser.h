#ifndef _SceneParser_H_
#define _SceneParser_H_

#include "vectors.h"
#include "group.h"
#include "camera.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"
#include "triangle.h"
#include "transform.h"


class Group;
class Camera;
class Sphere;

#define MAX_PARSER_TOKEN_LENGTH 100

// ====================================================================
// ====================================================================

class SceneParser {

public:

  // CONSTRUCTORS, DESTRUCTOR & INITIALIZE
  SceneParser();
  SceneParser(const char *filename);
  ~SceneParser();

  // ACCESSORS
  Group* getGroup() { return group; }
  Camera* getCamera() { return camera; }
  int getNumLights(){return num_lights;}
  Light* getLight(int i){return lights[i];}
  Vec3f getAmbientLight(){return ambient_light;}
  Vec3f getBackgroundColor() { return background_color; }

private:

  // HELPER FUNCTIONS
  void initialize();
  int getToken(char token[MAX_PARSER_TOKEN_LENGTH]);
  int readInt();
  float readFloat();
  Vec3f readVec3f();

  //kinds of parse fun
  void parseFile();//Èë¿Ú
  
  void parseOrthographicCamera();
  void parsePerspectiveCamera();
  void parseLights();
  void parseBackground();
  void parsePhongMaterials();

  Group* parseGroup();
  Object3D *parseObject(char token[MAX_PARSER_TOKEN_LENGTH]);

  Sphere* parseSphere();
  Transform* parseTransform();
  Group* parseTriangleMesh();
  Triangle* parseTriangle();
  Plane* parsePlane();
  
  // REPRESENTATION
  Group *group;
  Camera *camera;
  Light **lights;
  PhongMaterial *materials;

  int num_lights;
  int num_materials;
  Vec3f ambient_light;
  Vec3f background_color;

  Vec3f current_object_color;
  FILE *file;

};

// ====================================================================
// ====================================================================

#endif
