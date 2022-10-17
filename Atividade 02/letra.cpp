#include <stdio.h>

int notas(float nota1, float nota2, float nota3, char letra){
	
	float media=0;
	
	if(letra=='a'){
		media=(nota1+nota2+nota3)/3;
		printf("Media aritmetica: %.2f\n", media);
	}else if(letra=='p'){
		media=((nota1*5)+(nota2*3)+(nota3*2))/10;
		printf("Media ponderada: %.2f\n", media);
	}else if(letra=='h'){
		media=3/((1/nota1)+(1/nota2)+(1/nota3));
		printf("Media harmonica: %.2f\n", media);
	}
}

int main(){

    notas(10,8,9,'a');
    notas(10,8,9,'p');
    notas(10,8,9,'h');
	
    return 0;
}
