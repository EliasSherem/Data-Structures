#include <stdio.h>

void prom(float num);

int main(){
	int valor[5];
	int i;
	int sum=0;
	
	for(i=0;i<5;i++){
		printf("Ingresa un numero: ");
		scanf("%d",&valor[i]);
	}
	for(i=0;i<5;i++){
		if(valor[i]%2==0){
			sum+=valor[i];
		}
	}
	printf("la suma de los numeros pares es: %d",sum);
	
}
