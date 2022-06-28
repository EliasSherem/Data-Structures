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
void Radix(struct nodo *, struct nodo *, struct nodo *, struct nodo *, struct nodo *, struct nodo *, struct nodo *, struct nodo *, struct nodo *,struct nodo *,int []);

int main(){
	struct nodo *lista_par=NULL;
	struct nodo *lista_impar=NULL;
	struct nodo *lista0=NULL;
	struct nodo *lista1=NULL;
	struct nodo *lista2=NULL;
	struct nodo *lista3=NULL;
	struct nodo *lista4=NULL;
	struct nodo *lista5=NULL;
	struct nodo *lista6=NULL;
	struct nodo *lista7=NULL;
	struct nodo *lista8=NULL;
	struct nodo *lista9=NULL;
	int opcion,x=0;
	int arreglo[10];
	int i;
	lista_par=new(nodo);
	lista_par->sig=NULL;
	lista_impar=new(nodo);
	lista_impar->sig=NULL;
	lista0=new(nodo);
	lista0->sig=NULL;
	lista1=new(nodo);
	lista1->sig=NULL;
	lista2=new(nodo);
	lista2->sig=NULL;
	lista3=new(nodo);
	lista3->sig=NULL;
	lista4=new(nodo);
	lista4->sig=NULL;
	lista5=new(nodo);
	lista5->sig=NULL;
	lista6=new(nodo);
	lista6->sig=NULL;
	lista7=new(nodo);
	lista7->sig=NULL;
	lista8=new(nodo);
	lista8->sig=NULL;
	lista9=new(nodo);
	lista9->sig=NULL;
	do{
		fflush(stdin);
		printf("1. Insertar\n2. Imprimir\n3. eliminar un dato\n4. par impar\n5. Radix\n6. Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: 
				system("cls");
				printf("Ingresa un entero: ");
				scanf("%d",&x);
				insertar(lista_par,x);
			break;
			case 2: 
				system("cls");
				imprimir(lista_par);
			break;
			case 3: 
				system("cls");
				printf("Ingresa el valor que desea eliminar: ");
				scanf("%d",&x);
				eliminar(lista_par,x);
			break;
			case 4:
				while(x!=999){
					system("cls");
					printf("Ingrese valores enteros y para dejar de insertar ingrese 999: ");
					scanf("%d",&x);
					if(x%2==0){
						insertar(lista_par,x);
					}else{
						if(x!=999){
							insertar(lista_impar,x);
						}
					}
				}
				printf("Lista par\n");
				imprimir(lista_par);
				printf("Lista impar\n");
				imprimir(lista_impar);
			break;
			case 5:
				i=0;
				do{
					system("cls");
					printf("Insrte un entero entre 0 y 9 (para dejar de insertar ingrese 999): ");
					scanf("%d",&x);	
					arreglo[i]=x;
					i++;
				}while(x!=999);
				Radix(lista0,lista1,lista2,lista3,lista4,lista5,lista6,lista7,lista8,lista9,arreglo);
			break;
			case 6: 
				borrarlista(lista_par);
				borrarlista(lista_impar);
				borrarlista(lista0);
				borrarlista(lista1);
				borrarlista(lista2);
				borrarlista(lista3);
				borrarlista(lista4);
				borrarlista(lista5);
				borrarlista(lista6);
				borrarlista(lista7);
				borrarlista(lista8);
				borrarlista(lista9);
				printf("Adios\n");
			break;
			default: printf("Opcion no valida\n");
			break;
		}
	}while(opcion!=6);
}

void insertar(struct nodo *inicio, int x){
	struct nodo *p,*q,*nuevo;
	nuevo=new(nodo);
	nuevo->info=x;
	p=inicio;
	while(p!=NULL){
		q=p;
		p=p->sig;
	}
	q->sig=nuevo;
	nuevo->sig=NULL;
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
void Radix(struct nodo *inicio0, struct nodo *inicio1, struct nodo *inicio2, struct nodo *inicio3, struct nodo *inicio4, struct nodo *inicio5, struct nodo *inicio6, struct nodo *inicio7, struct nodo *inicio8,struct nodo *inicio9,int  arreglo[]){
	 struct nodo *p;
	 int x=0;
	 int i;
	for(i=0;i<sizeof(arreglo);i++){
	 	if((arreglo[i])%10==0){
	 		insertar(inicio0,arreglo[i]);	
		 }else if((arreglo[i]-1)%10==0){
		 	insertar(inicio1,arreglo[i]);
		 }else if((arreglo[i]-2)%10==0){
		 	insertar(inicio2,arreglo[i]);
		 }else if((arreglo[i]-3)%10==0){
		 	insertar(inicio3,arreglo[i]);
		 }else if((arreglo[i]-4)%10==0){
		 	insertar(inicio4,arreglo[i]);
		 }else if((arreglo[i]-5)%10==0){
		 	insertar(inicio5,arreglo[i]);
		 }else if((arreglo[i]-6)%10==0){
		 	insertar(inicio6,arreglo[i]);
		 }else if((arreglo[i]-7)%10==0){
		 	insertar(inicio7,arreglo[i]);
		 }else if((arreglo[i]-8)%10==0){
		 	insertar(inicio8,arreglo[i]);
		 }else if((arreglo[i]-9)%10==0){
		 	insertar(inicio9,arreglo[i]);
		 }else{
		 }
		 
		}
		
	 	i=0;
	 	p=inicio0;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
	 	p=inicio1;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio2;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
	 	p=inicio3;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio4;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio5;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio6;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio7;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
		 
		p=inicio8;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
		 
		p=inicio9;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
		 
		for(i=0;i<sizeof(arreglo);i++){
	 	if((arreglo[i]%100)/10>1){
	 		insertar(inicio0,arreglo[i]);
		 }else if((arreglo[i]%100)/10>2){
		 	insertar(inicio1,arreglo[i]);
		 }else if((arreglo[i]%100)/10>3){
		 	insertar(inicio2,arreglo[i]);
		 }else if((arreglo[i]%100)/10>4){
		 	insertar(inicio3,arreglo[i]);
		 }else if((arreglo[i]%100)/10>5){
		 	insertar(inicio4,arreglo[i]);
		 }else if((arreglo[i]%100)/10>6){
		 	insertar(inicio5,arreglo[i]);
		 }else if((arreglo[i]%100)/10>7){
		 	insertar(inicio6,arreglo[i]);
		 }else if((arreglo[i]%100)/10>8){
		 	insertar(inicio7,arreglo[i]);
		 }else if((arreglo[i]%100)/10>9){
		 	insertar(inicio8,arreglo[i]);
		 }else if((arreglo[i]%100)/10>10){
		 	insertar(inicio9,arreglo[i]);
		 }else{
		 } 
		}
		
		i=0;
	 	p=inicio0;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
	 	p=inicio1;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio2;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
	 	p=inicio3;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio4;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio5;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio6;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }

	 	p=inicio7;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
		 
		p=inicio8;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
		 
		p=inicio9;
	 	while(p!=NULL){
	 		p=p->sig;
	 		arreglo[i]=p->info;
	 		i++;
		 }
	 
	 system("cls");
	 printf("Lista impresa en orden\n");
	 for(i=0;i<sizeof(arreglo);i++){
	 	if(arreglo[i]!=NULL){
	 		printf("%d ",arreglo[i]);
		 }
	 }
	 printf("\n");
	 fflush(stdin);
	 getchar();
}

