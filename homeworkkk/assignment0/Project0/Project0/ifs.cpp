#include "ifs.h"
#include "image.h"
#include <stdlib.h>
#include <time.h>


//弄一个点集，对它们做一些变换。然后按这些点的位置整出一幅图来，并存储
void Ifs::render(){
	Vec2f *points;
	points = new Vec2f[pointsnum];


	//let's go with all the points that are in (0,1)

	//GENERATE RANDOM POINTS
	srand(time(NULL));
	for(int i=0;i!=pointsnum;i++){
		points[i].Set(float(rand()%RAND_MAX)/RAND_MAX,
			float(rand()%RAND_MAX)/RAND_MAX);
	}


	Image image(width, height);
	char buff[255];
	Vec3f blackspot = Vec3f(0,0,0);

	//ITERATION
	for(int i=0; i!=iternum; i++){
		//for every point
		for(int p_=0; p_!=pointsnum; p_++){
			//choose a random transtration method with respect to the P[](probolity)
			double probability=double(rand()%RAND_MAX)/RAND_MAX;
			int k;
			for(k=0;k!=nnum;k++){
				if(probability<p[k])break;
			}
			trans[k].Transform(points[p_]);
		}
	    
		//save every iter image
		image.SetAllPixels(Vec3f(1,1,1));
		float x,y;
		for(int j=0;j!=pointsnum;j++){
			x = points[j].x();y = points[j].y();

			if(x>=1 || y>=1 || x<0 || y<0)continue;

			x*=width;y*=height;

			image.SetPixel(int(x), int(y),blackspot); 
		}
		sprintf(buff, "%s%d.tga", output_file, i);
		image.SaveTGA(buff);

	}

	



	delete [] points;
}

