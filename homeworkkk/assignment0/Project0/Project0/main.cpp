#include "vectors.h"
#include "matrix.h"
#include "ifs.h"
#include "image.h"
#include <stdio.h>
#include <stdlib.h>

void parse(int argc, char** argv, int &size, int &pointsnum, int &iternum, char * (&input_file), char *(&output_file)){

	size = 100;	
	iternum = 10;
	pointsnum = 10000;

	output_file = NULL;	input_file = NULL;	

	// sample command lines:
	//ifs -input fern.txt -points 10000 -iters 10 -size 100 -output fern

	for (int i = 1; i < argc; i++) {
	  if (!strcmp(argv[i],"-size")) {
		i++; assert (i < argc); 
		size = atoi(argv[i]);
	  } else if (!strcmp(argv[i],"-iters")) {
		i++; assert (i < argc); 
		iternum = atoi(argv[i]);
	  } else if (!strcmp(argv[i],"-points")) {
		i++; assert (i < argc); 
		pointsnum = atoi(argv[i]);
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

	int size,pointsnum, iternum;
	char * input_file;
	char * output_file;

	//ifs -input fern.txt -points 10000 -iters 10 -size 100 -output fern.tga
	parse(argc, argv, size, pointsnum, iternum, input_file, output_file);
	

	Ifs ifs=Ifs(size, size, 
		iternum, 
		input_file,output_file,
		pointsnum);
	
	ifs.render();

	return 0;
}



