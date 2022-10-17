#include <stdio.h>

int absoluto(int n[5]){
	
	for(int i=0; i<5;i++){
		
		if(n[i]<0){
			n[i]=n[i]*(-1);
		}
		printf("Resultado: %d\n",n[i]);
	}	
}

int main(){
	
	int n[5]={-2,-2,5,3,-10};
	int m[5]={-2,4,5,-8,-1};
	
	absoluto(n);
	absoluto(m);
	
	return 0;
}
