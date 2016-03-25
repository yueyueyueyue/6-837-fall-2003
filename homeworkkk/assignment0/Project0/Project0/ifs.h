#ifndef _IFS_H
#define _IFS_H

#include "matrix.h"
#include "vectors.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

class Ifs{

public:

	//CONSTRUCTOR AND DESTRUCTOR
	Ifs(int width, int height, 
		int iternum, 
		char *input_file, char* output_file,
		int pointsnum)
		:width(width),height(height),
		 iternum(iternum),
		 input_file(input_file), output_file(output_file),
		 pointsnum(pointsnum){
			readDescription();//读取变换矩阵文件
	}

	~Ifs(){
		delete [] trans;
		delete [] p;
	}
	
	//WORK
	void render();

	//ACCESSORS
private:
	void readDescription(){
		FILE *file=fopen(input_file, "r");
		fscanf(file, "%d", &nnum);
		trans = new Matrix[nnum];
		p = new float[nnum];
		for(int i=0;i!=nnum;i++){
			fscanf(file, "%f", &p[i]);
			trans[i].Read3x3(file);
		}
		fclose(file);

		for (int i=1;i!=nnum;i++){
			p[i] += p[i-1];		
		}
	}


private:
	int nnum;
	Matrix *trans;
	float *p;
	int width;
	int height;
	int iternum;
	int pointsnum;
	char * output_file;
	char * input_file;
};

#endif