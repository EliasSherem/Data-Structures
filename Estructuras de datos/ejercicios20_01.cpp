#include <stdio.h>
#include <stdlib.h>

float promedio(float []);
int suma(int[]);
void apuntador();
void apunta();
void apuntadores();
void cambio(int *);
void multiplicar(int *, int *);
int main(){
	int opcion=0;
	float cali[]={6.6,7.8,9,9.3,10};
	int arreglo[3],x,i;
	float prom;
	int j=155;
	int a=30,b=3;
	
	do{
		printf("\nIngrese la opcion del programa que desea: \n1. promedio\n2. suma\n3. apuntadores\n4. apuntadores2\n");
		printf("5. apuntadores3\n6. apuntadores4\n7. apuntadores5\n10. salir\n");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
		case 1: prom=promedio(cali);
		printf("El promedio es: %f",prom);
		break;
		case 2: 
		for(i=0;i<3;i++){
			printf("Dame un numero: ");
			scanf("%d",&arreglo[i]);
		}
		x=suma(arreglo);
		printf("la suma es: %d",x);
		break;
		case 3: apuntador();
		break;
		case 4: apunta();
		break;
		case 5:apuntadores();
		break;
		case 6: cambio(&j);
		printf("%d",j);
		break;
		case 7: multiplicar(&a,&b);
		break;
		case 10: printf("Adios");
		break;
		default: printf("Opcion invalida");
		break;
		}
	}while(opcion!=10);
	
}
float promedio(float cali[]){
	int i;
	float sum=0,prom=0;
	for(i=0;i<5;i++){
		sum+=cali[i];
	}
	prom=sum/5;
	return prom;
}
int suma(int arreglo[]){
	int s=0;
	int i;
	for(i=0;i<3;i++){
		s+=arreglo[i];
	}
	return s;
	
}
void apuntador(){
	int i;
	i=25;
	printf("%u",&i);
	getchar();
}
void apunta(){
	int i;  //declarando una variable entera llamada i
	int *p; //declarando un apuntador llamado p, a una variable entera
	i = 43;
	p = &i;  //guardando en p la dirección de la variable i
	printf("despliega el valor de i: %d\n", i);	//despliega 43
	printf("despliega la direccion de la variable i usando p: %u\n", p);	//despliega la dirección de la variable i, por ejemplo 4094
	printf("despliega la direccion de la variable i: %u\n", &i); //despliega la dirección de la variable i, igual que el anterior 4094
	printf("despliega el valor de i usando p: %d\n", *p);  //despliega 43, el valor referenciado por el apuntador  p
	printf("despliega la direccion de p: %u\n", &p); 
	getchar();
}
void apuntadores(){
	int a=30,b=3;
	int *ptra,*ptrb;
	int multi;
	ptra=&a;
	ptrb=&b;
	multi=(*ptra)*(*ptrb);
	printf("%d",multi);
}
void cambio(int *apunt){
	*apunt =351;
}
void multiplicar(int *pa, int *pb){
	int m=*pa**pb;
	printf("%d",m);
}
