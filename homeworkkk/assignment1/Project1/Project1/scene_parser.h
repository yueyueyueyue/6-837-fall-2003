#ifndef _SceneParser_H_
#define _SceneParser_H_

#include "vectors.h"
#include "object3d.h"
#include "camera.h"


#define MAX_PARSER_TOKEN_LENGTH 100

// ====================================================================
// ====================================================================
//用法：SceneParser("scene.txt");
//这样就得到了场景的camera、background、group了，都存在SceneParser类里头

class SceneParser {

public:

  // CONSTRUCTORS, DESTRUCTOR & INITIALIZE
	SceneParser();
  SceneParser(const char *filename);
  ~SceneParser();

  // ACCESSORS
  Group* getGroup() { return group; }
  Camera* getCamera() { return camera; }
  Vec3f getBackgroundColor() { return background_color; }

private:

  // HELPER FUNCTIONS
  //初始化各种指针为NULL，初始化背景色，Object3D颜色
  void initialize();


  //开始parse工作
  void parseFile();
  //读取的文件有三大块:CAMERA BACKROUND GROUP

  

  //读取各种camera的函数
  void parseOrthographicCamera();
  //void parsePerspectiveCamera();
  //读取背景，材料的函数
  void parseBackground();
  void parseMaterial();
  //读取group的函数
  Group* parseGroup();
  //读取Object3D的函数
  Sphere* parseSphere();
  Object3D* parseObject(char token[MAX_PARSER_TOKEN_LENGTH]); 



  //读基本数据的一些函数
  int getToken(char token[MAX_PARSER_TOKEN_LENGTH]);
  Vec3f readVec3f();
  float readFloat();
  int readInt();
  
  // REPRESENTATION
  Group *group;
  Camera *camera;
  Vec3f background_color;

  //用来读入的时候用的变量
  Vec3f current_object_color;
  FILE *file;

};

// ====================================================================
// ====================================================================

#endif
