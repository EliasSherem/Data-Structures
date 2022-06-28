#include <stdio.h>
#include <stdlib.h>

struct par{
	int info;
	struct par *sig;
};
struct impar{
	int info;
	struct impar *sig;
};

void insertar(struct par *,struct impar *, int);
void imprimir(struct par *, struct impar *);
void borrarlista(struct par *, struct impar *);
void eliminar(struct par *,struct impar *, int);

int main(){
	struct par *lista1=NULL;
	struct impar *lista2=NULL;
	int x=0;
	lista1=new(par);
	lista2=new(impar);
	lista1->sig=NULL;
	lista2->sig=NULL;
	while(x!=999){
		printf("Inserte un entero: (para dejar de insertar datos ingrese 999)");
		scanf("%d",&x);
		if(x!=999)
			insertar(lista1,lista2,x);
		system("cls");
	}
	imprimir(lista1,lista2);
	borrarlista(lista1,lista2);
	
}

void insertar(struct par *inicio1,struct impar *inicio2, int x){
	struct par *p,*q,*nuevo;
	struct impar *j,*k,*nuevo1;
	if(x%2==0){
		nuevo=new(par);
		nuevo->info=x;
		p=inicio1;
		while(p!=NULL){
			q=p;
			p=p->sig;
		}
		q->sig=nuevo;
		nuevo->sig=NULL;	
	}else{
		nuevo1=new(impar);
		nuevo1->info=x;
		j=inicio2;
		while(j!=NULL){
			k=j;
struct impar *p,*q,*nuevo;			j=j->sig;
		}
		k->sig=nuevo1;
		nuevo1->sig=NULL;
	}

}
void imprimir(struct par *inicio1,struct impar *inicio2){
	struct par *i;
	struct impar *j;
	i=inicio1;
	i=i->sig;
	j=inicio2;
	j=j->sig;
	system("cls");
	printf("Lista par\n");
	while(i!=NULL){
		printf("%d\n",i->info);
		i=i->sig;
	}
	printf("Lista impar\n");
	while(j!=NULL){
		printf("%d\n",j->info);
		j=j->sig;
	}
	fflush(stdin);
	getchar();
	system("cls");
}

void borrarlista(struct par *inicio1,struct impar *inicio2){
	struct par *p,*q;
	struct impar *j,*k;
	j=inicio2;
	j=j->sig;
	p=inicio1;
	p=p->sig;
	while(p!=NULL){
		q=p;
		p=p->sig;
		free(q);
	}
	while(j!=NULL){
		k=j;
		j=j->sig;
		free(k);
	}
}

void eliminar(struct par *inicio, int x){
	struct par *p,*q,*aux;
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
