#ifndef _SceneParser_H_
#define _SceneParser_H_

#include "vectors.h"
#include "object3d.h"
#include "camera.h"


#define MAX_PARSER_TOKEN_LENGTH 100

// ====================================================================
// ====================================================================
//�÷���SceneParser("scene.txt");
//�����͵õ��˳�����camera��background��group�ˣ�������SceneParser����ͷ

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
  //��ʼ������ָ��ΪNULL����ʼ������ɫ��Object3D��ɫ
  void initialize();


  //��ʼparse����
  void parseFile();
  //��ȡ���ļ��������:CAMERA BACKROUND GROUP

  

  //��ȡ����camera�ĺ���
  void parseOrthographicCamera();
  //void parsePerspectiveCamera();
  //��ȡ���������ϵĺ���
  void parseBackground();
  void parseMaterial();
  //��ȡgroup�ĺ���
  Group* parseGroup();
  //��ȡObject3D�ĺ���
  Sphere* parseSphere();
  Object3D* parseObject(char token[MAX_PARSER_TOKEN_LENGTH]); 



  //���������ݵ�һЩ����
  int getToken(char token[MAX_PARSER_TOKEN_LENGTH]);
  Vec3f readVec3f();
  float readFloat();
  int readInt();
  
  // REPRESENTATION
  Group *group;
  Camera *camera;
  Vec3f background_color;

  //���������ʱ���õı���
  Vec3f current_object_color;
  FILE *file;

};

// ====================================================================
// ====================================================================

#endif
