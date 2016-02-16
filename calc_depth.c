/*
 * PROY1-1: PARTE A
 *
 * Siéntase libre de definir funciones auxiliaresssss
 */

#include "calc_depth.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
int sqr(int a);

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
	int l = 0; 
	int m = 0;
	char featurel[2*feature_width+1][2*feature_height+1];
	char featurer[2*feature_width+1][2*feature_height+1];
	for (int j2 = 0; j2<2*feature_height+1; j2++){
		for(int j = 0; j<2*feature_width+1; j++){
			l = l + j;
			featurel[j2][j]= *(left+l); 
		}
		l = l +image_width;
	}

	for (int k2 = 0; k2<2*feature_height+1; k2++){
		for(int k = 0; k<2*feature_width+1; k++){
			m = m + k;
			featurer[k2][k]= *(right+m); 
		}
		m = m +image_height;
	}

	for(int u = 0; u<2*feature_height+1; u++){
		for(int u2 = 0; u2 <2*feature_width+1; u2++){
			while(featurel[u][u] != featurer[u][u2]){
				*(depth_map+u2) = 0; 
			}
			*(depth_map+u2)= 255;	
		}
	}
	/*for(i= 0; i < image_width*image_height; i++){
		*(depth_map+i) = 0;
			if(i == k){d
				for (j = 11; j>0; j--){
					//printf("i=%d\nj=%d\n%d\n",i,j,*(depth_map+(i-j)));
					*(depth_map+(i-j))=255;
					if (left+0 == right+(i-j)){
						printf("%s\n","yeih");
					}
				}
			k = k + image_width;
			}
	}*/
/*
					for(j=0;j<section_width;j++){
					        for(i=0;i<section_width;i++){
					            //pos+section_width 
					            if(t==*(depth_map+pos+i)){
					                t=*(depth_map+pos+i);
					            }else{
					                return 256;
					            }
					        }
					        pos=pos+map_width;
					    }
*/
		//for(int o = 0; o<50 = 0++)
		//	*(depth_map+o) = 128; 
		//	for(int u = 0; u <50 )
		/* YOU CODE HERE*/
}
int distan_eucli(char a[], char b[], int len){
	int i; 
	char k, m;
	int res = 0;
	for(i = 0; i < len; i++){
		k = a[i];
		m = b[i]; 
		res = res + ((k-m)*(k-m)); 
		}
	return res;
}