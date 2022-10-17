#include <stdio.h>

int SomaDivisores(int n[5]){
	
	int divisor, soma[5]={0,0,0,0,0};
	
	for(int i=0; i<5;i++){
		
		for(divisor=1;divisor<n[i];divisor++){
			if(n[i]%divisor == 0){
			soma[i] = soma[i] + divisor;
			}
		}
		printf("Resultado: %d\n",soma[i]);	
	}	
}

int main(){
	
	int n[5]={10,8,4,5,6};
	
	SomaDivisores(n);
	
	return 0;
}
