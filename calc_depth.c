/*
 * PROY1-1: PARTE A
 *
 * Siéntase libre de definir funciones auxiliaresssss
 */

#include "calc_depth.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
int distan_eucli(int a, int b, int c);

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
	//int es = 0;
	//int a1 = 0; 
	int top = 0;
	char featurel [2*feature_width+1] [2*feature_height+1];
	//char featurer [2*feature_width+1] [2*feature_height+1];
	
	// 0 en depth.
	for(int i = 0; i<image_width; i++){ *(depth_map+i) = 0; }
	for(int y = image_height*image_width; y>(image_width*image_height)-image_width; y--){ *(depth_map+y) = 0; }
	for(int j = 0; j<image_width*image_height; j= j + image_width){ *(depth_map+j) = 0; *(depth_map+(j-1)) = 0; }

	// x(1,1).
	//parche left.
	for(int k = 1+image_width; k<image_width*image_height; k++){
		//int top = k-1-image_width;
		for(int q = 1; q<image_height; q++){
			for(int w = 0; w<(2*feature_width+1); w++){
				for(int x= 0; x<(2*feature_width+1); x++){
					for(int x= 0; x<(2*feature_width+1); x++){
						featurel[w][x] = *(left+(top+x));
						featurer[w][x] = *(right+(top+x));		
						*(depth_map+k) = 255;
					}
				}
			top = top + image_width; 
			}
		}
	}
}
		/*
		//	if (((k-image_width > 0) && (q-image_height > 0)) && (((k-image_width)+2*feature_width+1 < image_width) && ((q-image_height)+2*feature_height+1 < image_height))){
				
				//	a1 = featurel[w][x];
						b1 = featurer[w][w]; 
						es = distan_eucli(a1, b1, 1);
						if(es != 0){
							*(depth_map)= 0; 
						}
						if(es == 0){
							*(depth_map) = 128;
					}
				}
			}
		//}
		top = top+image_width;
	//}
}
}
*/
int distan_eucli(int k, int m, int c){
		int res = ((k-m)*(k-m)); 
		if (res == 0){
			return 0;
		}
	return res;
}
/*int distan_eucli(char a[], char b[], int len){
	int i; 
	char k, m;
	int res = 0;
	for(i = 0; i < len; i++){
		k = a[i];
		m = b[i]; 
		res = res + ((k-m)*(k-m)); 
		}
	return res;
}*/
