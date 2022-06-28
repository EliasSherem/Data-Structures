#include <stdio.h>

float comprueba(float *, float*);

int main(){
	float x=10.5,y=5.5;
	float mayor;
	mayor=comprueba(&x,&y);
	printf("El mayor es: %f", mayor);
	
}

float comprueba(float *a, float *b){
	if(*a>*b){
		return *a;
	}else{
		return *b;
	}
}
