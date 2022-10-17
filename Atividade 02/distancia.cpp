#include <stdio.h>

int distancia(int x1, int y1, int x2, int y2){
	
	float media1=0, media2=0;
	
	media1 = x1-y1;
	media2 = x2-y2;
	
	if(media1<0){
		media1 = (x1-y1)*(-1);
	}
	if(media2<0){
		media2 = (x2-y2)*(-1);
	}
	
	printf("Distancia entre x1 e y1: %.2f\n", media1);
	printf("Distancia entre x2 e y2: %.2f\n", media2);	
	
}


int main(){
	

	distancia(5,2,10,5);
	
	
	return 0;
}