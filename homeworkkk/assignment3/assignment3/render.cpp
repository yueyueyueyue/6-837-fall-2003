#include "vectors.h"
#include "matrix.h"
#include "image.h"
#include "ray.h"
#include "scene_parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void parse(int argc, char** argv, Vec2f &size, char * (&input_file), char *(&output_file)){
	
	size.Set(100, 100);

	output_file = NULL;	input_file = NULL;	

	// sample command lines:
	//raycast -input scene.txt -size 100 100 -output image.tga

	for (int i = 1; i < argc; i++) {
	  if (!strcmp(argv[i],"-size")) {
		i++; i++; assert (i < argc); 
		size.Set( atoi(argv[i-1]), atoi(argv[i])) ;

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



	//redering...
	Camera* camera=sp.getCamera();
	Group*  group =sp.getGroup();
	int i,j,h=size.y(),w=size.x();
	Image img(w,h);
	img.SetAllPixels(sp.getBackgroundColor());
	float y,x;//[0,1]
	Ray ray;
	float *dep=new float[w*h];
	Vec3f *normal=new Vec3f[w*h];
	float depmax,depmin, z;
	Vec3f col;
	float  weight;
	
	Vec3f camnormal=((PerspectiveCamera*)camera)->getDir();
	float maxfloat = std::numeric_limits<float>::max();
    float minfloat = std::numeric_limits<float>::lowest();
	depmax = 0; depmin = maxfloat;
	//扫描每个像素点
	for(i=0;i!=h;i++){
		y = (float)i/(h-1);
	    for(j=0;j!=w;j++){
		    x = (float)j/(w-1);
			ray = camera->generateRay(Vec2f(x,y));
	        Hit hit(maxfloat,&Vec3f(0,0,0),Vec3f(0,0,0));
			if(group->intersect(ray, hit, -1)){
				Light* light;
				Vec3f ldir,lcol;
				Vec3f lcol_sum(0,0,0);
				float weight;
				Vec3f col=*hit.getMaterial();


				Vec3f pixelcol=col*sp.getAmbientLight();
				for(int k=0;k!=sp.getNumLights();k++)
				{
					light = sp.getLight(k);

					light->getIllumination(hit.getIntersectionPoint() ,ldir, lcol);

					weight = ldir.Dot3(hit.getNormal());

					if(weight>0){
						pixelcol = pixelcol + weight*col*lcol;
					}

				}
				//col = *hit.getMaterial();
				//col = sp.getDiffusePixelCol(col, hit);

				img.SetPixel(j,i,pixelcol);



				z = (hit.getIntersectionPoint() - ray.getOrigin()).Dot3(camnormal);
				//z = hit.getT();
				dep[i*w+j] = z;
				if(z<depmin)depmin=z;if(z>depmax)depmax=z;

				normal[i*w+j] = hit.getNormal();
			}
		}
	}
	img.SaveTGA(output_file_name);


	//render depth********************************************************************************
	//存深度
	img.SetAllPixels(Vec3f(0,0,0));
	for(i=0;i!=h;i++){
	    for(j=0;j!=w;j++){
		    z = dep[i*w+j];// = z;
			z = (z-depmin)/(depmax-depmin);
			img.SetPixel(j,i,Vec3f(1-z,1-z,1-z));
		}
	}
	//store the pic
	int len = strlen(output_file_name);
	//output_file_name[len-4]=0;
	char buff[255];
	strncpy(buff,output_file_name,len-4);
	buff[len-4]=0;
	strcat(buff,"_depth.tga");
	img.SaveTGA(buff);

	//render normal*******************************************************************************
	//存normal
	img.SetAllPixels(Vec3f(0,0,0));
	for(i=0;i!=h;i++){
	    for(j=0;j!=w;j++){
			Vec3f normal_abs(abs(normal[i*w+j].x()), abs(normal[i*w+j].y()), abs(normal[i*w+j].z()));
			img.SetPixel(j,i,normal_abs);
		}
	}
	//store the pic
	len = strlen(output_file_name);
	//output_file_name[len-4]=0;
	strncpy(buff,output_file_name,len-4);
	buff[len-4]=0;
	strcat(buff,"_normal.tga");
	img.SaveTGA(buff);

	return 0;
}