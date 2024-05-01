#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char *argv[]) 
{
	typedef struct 
	{
		int dado;
		struct no *prox;
	} no;
	
	no *lista, *p, *q;
	int esc, cont, pos,i;
	lista = NULL;
	
	printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado à esquerda (ínicio da lista) \n 2. Fazer inserção à direita (final da lista) \n 3. Fazer inserção intermediária \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
	
	do {
		switch (esc) {	
		
		case 1:
			p = malloc (sizeof(no));
			printf("Digite o dado na lista: ");
			scanf("%i", &p ->dado);
			p -> prox = lista;
			lista = p;
			printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado à esquerda (ínicio da lista) \n 2. Fazer inserção à direita (final da lista) \n 3. Fazer inserção intermediária \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
		break;

		case 2:
			if (lista == NULL) 
			{  // Check se a lista permite inserção à direita
				p=malloc(sizeof(no)); 
				printf("Digite o dado na lista: ");
				scanf("%i", &p ->dado);
				lista = p;
				printf("O dado foi inserido a esquerda pois não tem dados suficientes na lista.");
			} else 
			{
				p = malloc(sizeof(no));
				printf("Digite o dado na lista: ");
				scanf("%i", &p -> dado);
				p -> prox = NULL; //final da lista
				q = lista;
				while (q-> prox!= NULL)
				{
					q = q->prox;
				}
				printf("enderço entregue ao p: %i", q->prox, setlocale(LC_ALL,""));
				q->prox = p;
			};
			printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado à esquerda (ínicio da lista) \n 2. Fazer inserção à direita (final da lista) \n 3. Fazer inserção intermediária \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
		break;
		
		case 3:
			if (lista == NULL) 
			{  // Check se a lista existe
				printf("sem dados na Lista. \n");
			} else
				{
					cont = 1;
					q = lista;
					while (q -> prox != NULL)
					{
						q = q->prox;
						cont++;
					}
					printf("Escreva em qual posição deseja fazer a inserção %i \n", cont++);
					scanf("%i", &pos);
					
					if(pos > cont++ )
					{
						printf("posição inválida", setlocale(LC_ALL,""));
					} else
						{
							if(pos == cont++)
							{
								//Inserção à direita para o dado no final da lista
								p = malloc(sizeof(no));
								printf("Digite o dado na lista: ");
								scanf("%i",&p->dado);
								p->prox = NULL;
								q = lista;
								while(q->prox != NULL)
								{
									q = q->prox;
								}
								q->prox = p;
							} else 
								{
									p = malloc(sizeof(no));
									printf("Digite o dado na lista: ");
									scanf("%i",&p->dado);
									q = lista;
									for(i = 0; i < pos - 2;i++)
									{
										q = q->prox;
									}
									p->prox = q->prox;
									q->prox = p;
								}
						}
				}
		printf("\n O que deseja fazer na Lista? \n 1. Inserir um dado à esquerda (ínicio da lista) \n 2. Fazer inserção à direita (final da lista) \n 3. Fazer inserção intermediária \n 4. Sair do menu e ver a Lista \n", setlocale(LC_ALL,""));
		break;
		
		case 4:
		 return(0);
		};
		
		scanf("%i", &esc);
	} while (esc != 4);
	
	printf("Lista:\n");
	p = lista;
	while (p -> prox != NULL)
	{
	  printf("%i \n", p -> dado);
	  p = p -> prox;
	}; printf("%i \n", p -> dado);
};
