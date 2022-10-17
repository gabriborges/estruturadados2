#include <stdio.h>
#include <stdlib.h>

struct distancia{

 float media1;
 float media2;
 
};
typedef struct distancia Distancia;

void calcular(Distancia** dis, int n, float x1, float y1, float x2,float y2){
	
 	for(int i = 0; i < n; i++){
 		
 	dis[i] = (Distancia*)malloc(sizeof(Distancia));
 	
	dis[i]->media1 = x1-y1;
	dis[i]->media2 = x2-y2;
	
	if(dis[i]->media1<0){
		dis[i]->media1 = (x1-y1)*(-1);
	}
	if(dis[i]->media2<0){
		dis[i]->media2 = (x2-y2)*(-1);
	}
	
	printf("Distancia entre x1 e y1: %.2f\n", dis[i]->media1);
	printf("Distancia entre x2 e y2: %.2f\n", dis[i]->media2);
	
	}
}


int main(){
	Distancia* dis[1];
	
	calcular(dis,1,10,6,20,8); 
	
 return 0;
}
