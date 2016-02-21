/*
 * PROY1-1: PARTE A
 *
 * Siéntase libre de definir funciones auxiliaresssss
 */

#include "calc_depth.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>

unsigned char normalized_displacement(int, int, int);

/* Implementación de la función de desplazamiento normalizado*/
unsigned char normalized_displacement(int dx, int dy,
        int maximum_displacement) {

    double squared_displacement = dx * dx + dy * dy;
    double normalized_displacement = round(255 * sqrt(squared_displacement) / sqrt(2 * maximum_displacement * maximum_displacement));
    return (unsigned char) normalized_displacement;

}

void calc_depth(unsigned char *depth_map, unsigned char *left,
                unsigned char *right, int image_width, int image_height,
                int feature_width, int feature_height, int maximum_displacement) {
	int es = 0;
	int a = 666666666; 
	//int topl = 0;
	//int topr = 0;
	char pop= 0; 
	char m = 0; 				
	char featurel [2*feature_width+1] [2*feature_height+1];
	char featurer [2*feature_width+1] [2*feature_height+1];
	int maxab = maximum_displacement*image_width; 
	int maxlr = maximum_displacement;
	int tama = maximum_displacement*image_width;
	int tamb = maximum_displacement*image_height; 
	int temi = maximum_displacement;
	int temd = maximum_displacement; 
	// 0 en depth.
	for(int i = 0; i<image_width; i++){ *(depth_map+i) = 0; }
	for(int y = image_height*image_width; y>(image_width*image_height)-image_width; y--){ *(depth_map+y) = 0; }
	for(int j = 0; j<image_width*image_height; j= j + image_width){ *(depth_map+j) = 0; *(depth_map+(j-1)) = 0; }
	// x(1,1).
	//parche left.
	for(int k = image_height; k<image_width*image_height; k = k + image_width){
		for(int q = 1; q<image_width; q++){
			if(((k-(2*feature_width+1*image_height)>0) && (q-2*feature_width+1 > 0)) || ((k+(2*feature_height+1*image_width) < image_width*image_height) && ((q+2*feature_width)<image_width))){
				for(int w = 0; w<2*feature_width+1; w++){
					for(int x= 0; x<2*feature_width+1; x++){
						featurel[w][x] = *(left+(k+q));
					}
				}
				//parche de right.
				if(k < maxab){ tama = maxab -(maxab - k); }
				if(k+maxab > image_width*image_height){ tamb =  image_width +(image_width*image_height-k-maxab); } 
				if(q < maxlr){ temi = maxlr - (maxlr-q);} 
				if(k+maxlr > image_height){temd = maxlr + (image_width-q-maxlr);}
				for(int gg = k-tama; gg<tamb+tamb+image_width;  gg= gg + image_width){	
					for(int gg2 = q-temi; gg2<temd+temi; gg2++){
						for(int y = 0; y<2*feature_width+1; y++){
							for(int x=0; x<2*feature_height+1;x++){
								featurer[y][x] = *(right+(gg+gg2));
							}
						}
						for(int ii = 0; ii < 2*feature_width+1; ii++){
							for(int jj3= 0; jj3< 2*feature_height+1; jj3++){
								pop = featurel[ii][jj3];
								m = featurer[ii][jj3];
								es = ((pop-m)*(pop-m)); 
								if(es == 0){
									*(depth_map+(k+q)) = es;
								}
								//if(es != 0){
								//	*(depth_map+(k+q)) = es;
								//}
							}
						}
					}
				}/*
							if(es < a){
								//printf("%d\t", es);
								//
								*(depth_map+k) = 255;
								a = es;
				*/
				//k = k + image_height;		
			}
		}
	}
}
