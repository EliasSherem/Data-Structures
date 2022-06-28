#include <stdio.h>

int main(){
	int valor[]={3,5,7,9,10,11,13,14,16,18,20};
	int i,x,flag=0;
		
	printf("Ingresa un numero: ");
	scanf("%d",&x);
	for(i=0;i<11;i++){
		if(valor[i]==x){
			printf("se encontro el valor %d en la posicion %d",x,i+1);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("No se encontro el valor");
	}
}
