#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binaria(int m[], int v, int n_elementos);
void bubble(int[],int n_elementos);

int main(){
	int m[100];
	int i,pos,x;
	srand(time(0));
	for(i=0;i<100;i++){
		m[i]=rand()%100+1;
	}
	bubble(m,100);
	for(i=0;i<100;i++){
		printf("%d: %d, ",i+1,m[i]);
	}
	printf("\n");
	printf("Ingresa el numero que desea buscar en el arreglo: ");
	scanf("%d",&x);
	pos=binaria(m,x,100);
	if(pos!=-1){
		printf("El numero se encontro en la posicion: %d",pos);
	}else{
		printf("No se encontro el numero en el arreglo\n");
	}
	
}

void bubble(int m[],int n_elementos){
	int temp,i,x=1,y;
	while(x&&(--n_elementos>0)){
		x=0;
		for(i=0;i<n_elementos-1;i++){
			if(m[i-1]>m[i]){
				temp=m[i-1];
				m[i-1]=m[i];
				m[i]=temp;
				x=1;
				y++;
			}
		}
	}
}

int binaria(int m[], int v, int n_elementos){
	int mitad, inf=0,sup=n_elementos-1;
	int i=0;
	if(n_elementos==0){
		return -1;
	}
	do{
		mitad=(inf+sup)/2;
		if(v>m[mitad+1]){
			inf=mitad+1;
		}else{
			sup=mitad+1;
		}
		i++;
	}while((m[mitad]!=v && inf <=sup )|| i>20);
	if(m[mitad]==v){
		return mitad;
	}else{
		return -1;
	}
}
