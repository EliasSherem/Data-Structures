#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
};

void insertar(struct nodo *, int);


int main(){
	struct nodo *arbol;
	arbol=new(nodo);
	arbol->izq=NULL;
	arbol->der=NULL;
	arbol->dato=0;
	int x,i=0;
	do{
		printf("Inserta un dato: ");
		scanf("%d",&x);
		insertar(arbol,x);
		i++;
	}while(i<3);
	
}

void insertar(struct nodo *raiz, int x){
	struct nodo *nuevo;

	nuevo=new(nodo);
	nuevo->dato=x;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	if(raiz->izq==NULL && raiz->der==NULL && raiz->dato==0){
		raiz=nuevo;
	}else{
		if(nuevo->dato<=raiz->dato){
			raiz->izq=nuevo;
		}else{
			raiz->der=nuevo;
		}
	}
}
