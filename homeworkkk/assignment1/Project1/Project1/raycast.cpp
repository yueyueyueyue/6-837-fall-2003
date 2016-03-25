#include "vectors.h"
#include "matrix.h"
#include "image.h"
#include "scene_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits>

void parse(int argc, char** argv, Vec2f &size, char * (&input_file), char *(&output_file)){
	
	size.Set(100, 100);

	output_file = NULL;	input_file = NULL;	

	// sample command lines:
	//raycast -input scene.txt -size 100 100 -output image.tga

	for (int i = 1; i < argc; i++) {
	  if (!strcmp(argv[i],"-size")) {
		i++; i++; assert (i < argc); 
		size.Set(atoi(argv[i-1]), atoi(argv[i])) ;

	  } else if (!strcmp(argv[i],"-output")) {
		i++; assert (i < argc); 
		output_file = argv[i];
	  } else if (!strcmp(argv[i],"-input")) {
		i++; assert (i < argc); 
		input_file = argv[i];
	  } else {
		printf ("whoops error with command line argument %d: '%s'\n",i,argv[i]);
		assert(0);
	  }
	}
}




int main(int argc, char** argv){

	Vec2f size;
	char * input_file_name;
	char * output_file_name;


	//raycast -input scene.txt -size 100 100 -output image.tga
	parse(argc, argv, size, input_file_name, output_file_name);


	SceneParser sp(input_file_name);//由场景说明文件得到camera backgroundcolor objects

	//绘制场景
	Camera* camera=sp.getCamera();
	Group*  group =sp.getGroup();
	int i,j,h=size.y(),w=size.x();
	Image img(w,h);
	img.SetAllPixels(sp.getBackgroundColor());
	float y,x;//[0,1]
	Ray ray;
	float *dep=new float[w*h];
	float depmax,depmin, z;
	

	float maxfloat = std::numeric_limits<float>::max();
    float minfloat = std::numeric_limits<float>::lowest();
	depmax = 0; depmin = maxfloat;
	//扫描每个像素点
	for(i=0;i!=h;i++){
		y = (float)i/(h-1);
	    for(j=0;j!=w;j++){
		    x = (float)j/(w-1);
			ray = camera->generateRay(Vec2f(x,y));
	        Hit hit(maxfloat,&Vec3f(0,0,0));
			if(group->intersect(ray, hit, -1)){
				img.SetPixel(j,i,*(hit.getMaterial()));
				z = hit.getT();//.getIntersectionPoint().z();
				dep[i*w+j] = z;
				if(z<depmin)depmin=z;if(z>depmax)depmax=z;
			}
		}
	}
	img.SaveTGA(output_file_name);

	//其实这里的深度只是个z啦，称不上是深度
	//存深度
	img.SetAllPixels(Vec3f(0,0,0));
	for(i=0;i!=h;i++){
	    for(j=0;j!=w;j++){
		    z = dep[i*w+j];// = z;
			z = (z-depmin)/(depmax-depmin);
			img.SetPixel(j,i,Vec3f(z,z,z));
		}
	}
	int len = strlen(output_file_name);
	//output_file_name[len-4]=0;
	char buff[255];
	strncpy(buff,output_file_name,len-4);
	buff[len-4]=0;
	strcat(buff,"_depth.tga");
	img.SaveTGA(buff);


	return 0;
}