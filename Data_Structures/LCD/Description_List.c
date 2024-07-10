#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	struct no{
		struct no *dir;
		int dado;
		struct no *esq;
	} ;
	
	struct descritor{
		struct no *inicio;
		int n;
		struct no *final;
	} ;
	
	struct descritor *d;
	struct no *p, *g;
	int sn;
	
//	Inicio
	d->inicio = NULL;
	d->final = NULL;
	d->n = 0;
	printf("Escreva os dados para insercao a direita\n");
	
	if(d->n == 0){
		p = malloc (sizeof(struct no));
		scanf("%i", &p -> dado);
		d->inicio = p;
		d->final = p;
	}
	do {
		p = malloc (sizeof(struct no));
		scanf("%i", &p -> dado);
		g = d -> final;
		g -> dir = p;
		p -> dir = NULL;
		printf("deseja escrever mais?");
		scanf("%i",&sn);	
	} while (sn == 1);
	
	printf("escrevendo a lista\n");
	p = d -> inicio;
	while(p->dir != NULL)
	{
		printf("%i \n", p-> dado);
		p = p-> dir;
	}
	
	return 0;
}