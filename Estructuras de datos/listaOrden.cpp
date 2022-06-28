#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int info;
	struct nodo *sig;
};

void insertar(struct nodo *, int);
void imprimir(struct nodo *);
void borrarlista(struct nodo *);
void eliminar(struct nodo *, int);

int main(){
	struct nodo *lista=NULL;
	int opcion,x;
	lista=new(nodo);
	lista->sig=NULL;
	do{
		fflush(stdin);
		printf("1. Insertar\n2. Imprimir\n3. eliminar un dato\n4. Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: 
				system("cls");
				printf("Ingresa un entero: ");
				scanf("%d",&x);
				insertar(lista,x);
			break;
			case 2: 
				system("cls");
				imprimir(lista);
			break;
			case 3: 
				system("cls");
				printf("Ingresa el valor que desea eliminar: ");
				scanf("%d",&x);
				eliminar(lista,x);
			break;
			case 4: 
				borrarlista(lista);
				printf("Adios\n");
			break;
			default: printf("Opcion no valida\n");
			break;
		}
	}while(opcion!=4);
}

void insertar(struct nodo *inicio, int x){
	struct nodo *p,*q,*nuevo;
	nuevo=new(nodo);
	nuevo->info=x;
	p=inicio;
	if(inicio==NULL){
		inicio=nuevo;
		nuevo->sig=NULL;
	}else{
		q=p;
		while(p!=NULL && p->info<nuevo->info){
			q=p;
			p=p->sig;
		}
		if(q==inicio){
			nuevo->sig=p;
			q->sig=nuevo;
		}else if(p==NULL){
			q->sig=nuevo;
			nuevo->sig=NULL;
		}else{
			q->sig=nuevo;
			nuevo->sig=p;
		}
	}
}
void imprimir(struct nodo *inicio){
	struct nodo *i;
	i=inicio;
	i=i->sig;
	while(i!=NULL){
		printf("%d\n",i->info);
		i=i->sig;
	}
	fflush(stdin);
	getchar();
	system("cls");
}

void borrarlista(struct nodo *inicio){
	struct nodo *p,*q;
	p=inicio;
	p=p->sig;
	while(p!=NULL){
		q=p;
		p=p->sig;
		free(q);
	}
}

void eliminar(struct nodo *inicio, int x){
	struct nodo *p,*q,*aux;
	p=inicio;
	q=p;
	aux=p;
	aux=aux->sig;
	p=p->sig;
	while(aux->info!=x && aux!=NULL) {
		q=q->sig;
		p=p->sig;
		aux=aux->sig;
	}
	if(aux->sig==NULL && aux->info==x){
		q->sig=NULL;
		free(aux);
	}else{
		p=p->sig;
		q->sig=p;
		free(aux);
	}
}
