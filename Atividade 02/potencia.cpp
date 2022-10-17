#include <stdio.h>

int potencia(int base, int expo){
	
	int aux=1;
	
	for(int i=0;i<expo;i++){
		aux=aux*base;
	}
	
	printf("Resultado: %d\n",aux);
	
}

int main(){
	
	potencia(3,3);
	potencia(3,4);
	
	return 0;
}
