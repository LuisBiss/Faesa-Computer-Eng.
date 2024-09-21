#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(int argc, char *argv[]) {
int esc;
printf("Escolha qual quest�o deseja ver a resposta:",setlocale(LC_ALL,""));
scanf("%i", &esc);
do {
	switch (esc) {
	case 1:
	{	// EXC 1
		int inteiro = 15;
		float real = 18.94;
		char charactere = 'c';
		
		printf("-- Quest�o 1: \nVari�vel do tipo inteiro: %i \nVari�vel do tipo real: %c \nVari�vel do tipo caractere: %f \n", inteiro, charactere,  real, setlocale(LC_ALL,""));
		
		printf("\nModifique o valor da vari�vel do tipo inteiro: \n", setlocale(LC_ALL,""));
		scanf("%i", &inteiro);
		
		printf("\nModifique o valor da vari�vel do tipo caractere: \n", setlocale(LC_ALL,""));
		scanf(" %c", &charactere);
		
		printf("\nModifique o valor da vari�vel do tipo real: \n", setlocale(LC_ALL,""));
		scanf("%f", &real);
		
		printf("Vari�vel do tipo inteiro: %i \n", inteiro, setlocale(LC_ALL,""));
		printf("Vari�vel do tipo real: %f \n", real, setlocale(LC_ALL,""));
		printf("Vari�vel do tipo caractere: %c \n", charactere, setlocale(LC_ALL,""));
	}break;
	
	case 2:
	{	//EXC 2
		int v1, v2;
		printf("-- Quest�o 2 \nEscreva as duas v�riaveis:\n", setlocale(LC_ALL,""));
		scanf("%i \n",&v1);
		scanf("%i",&v2);
		printf("Valor escrito da primeira vari�vel: %i \nValor da segunda vari�vel: %i \n", v1, v2,setlocale(LC_ALL,""));
		printf("Endere�o na mem�ria da primeira vari�vel: %p \nEndere�o na mem�ria da segunda vari�vel: %p", &v1, &v2,setlocale(LC_ALL,""));
	}break;
	
	case 3:
	{	//EXC3
		;int inteiro3;
		float num, frac;
		printf("-- Quest�o 3 \n",setlocale(LC_ALL,""));
		void sep(float num, int *inteiro3, float *frac)
		{
			*inteiro3 = (int) num;
			*frac = num - *inteiro3;
		};
		printf("Digite um n�mero real:\n", setlocale(LC_ALL,""));
		scanf("%f", &num);
		//Chamando a fun��o
		sep(num, &inteiro3, &frac);
		printf("Parte inteira: %i\n", inteiro3);
	  	printf("Parte fracion�ria: %f\n", frac);
	}break;
		
	case 4: 
	{	//EXC 4
		printf("-- Quest�o 4 \n",setlocale(LC_ALL,""));
		int unsigned i, qnt, tamanho;
		printf("\nEscreva a quantidade de n�meros no Array: ", setlocale(LC_ALL,""));
		scanf("%i", &tamanho);
		float vet[tamanho];
		printf("Escreva os valores reais em cada array: \n", setlocale(LC_ALL,""));
		for(i = 0; i < tamanho; i++)
		{
			printf("Digite o valor %i: ", i+1);
			scanf("%f", &vet[i]);
		};
		int N = sizeof(vet) / sizeof(vet[0]);
		printf("--------------------------------");
		int neg(float *vet, int N)
		{
			qnt = 0;
			for (i = 0; i < N; i++) 
			{
	   		 if ( vet[i] < 0)
				{
	      			qnt++;
	    		}
	    	};
	    	return qnt;
		};
		neg(vet,N);
		printf("\nQuantidade de valores negativos no array: %i\n", qnt);
	}break;
	
	case 5:
	{	//EXC 5
		printf("-- Quest�o 5 \n",setlocale(LC_ALL,""));
		int *min, *max;
		int unsigned i, tamanho;
		printf("\nEscreva a quantidade de n�meros no Array: ", setlocale(LC_ALL,""));
		scanf("%i", &tamanho);
		int vet[tamanho];
		printf("Escreva os valores inteiros em cada array: \n", setlocale(LC_ALL,""));
		for(i = 0; i < tamanho; i++)
		{
			printf("Digite o valor %i: ", i+1);
			scanf("%i", &vet[i]);
		};
		int N = sizeof(vet) / sizeof(vet[0]);
		printf("--------------------------------");
		
		void minmax(int vet[], int N, int *min, int *max)
		{
			*min = vet[0];
			*max = vet[0];
			for (i = 1; i < tamanho; i++) 
			{
		        if (vet[i] < *min) 
				{
		            *min = vet[i];
		        }
		        if (vet[i] > *max) 
				{
		            *max = vet[i];
		        }
	    	}
		}
		minmax(vet,N, &min, &max);
		printf("\nValor m�nimo: %i", min, setlocale(LC_ALL,""));
		printf("\nValor m�ximo: %i", max, setlocale(LC_ALL,""));
	}break;
	
	case 6:
	{	//EXC 6
		printf("-- Quest�o 6 \n",setlocale(LC_ALL,""));
		int max, rep;
		int unsigned i, qnt, tamanho;
		printf("\nEscreva a quantidade de n�meros no Array: ", setlocale(LC_ALL,""));
		scanf("%i", &tamanho);
		int vet[tamanho];
		printf("Escreva os valores inteiros em cada array: \n", setlocale(LC_ALL,""));
		for(i = 0; i < tamanho; i++)
		{
			printf("Digite o valor %i: ", i+1);
			scanf("%i", &vet[i]);
		};
		int N = sizeof(vet) / sizeof(vet[0]);
		printf("--------------------------------");
		void qst6(int vet[],int N, int *max, int rep)
		{
			*max = vet[0];
			rep = 1;
			for(i=1; i < N; i++)
			{
				if(vet[0] > *max)
				{
					*max = vet[i];
					rep = 1;
				} else if (vet[i] == *max)
				{
					rep++;
				}
			}
			printf("\nMaior valor: %i \nN�mero de repeti��es: %i", *max, rep);
		}
		qst6(vet, N, &max, rep);
	}break;
	
	case 7:
	{	//EXC 7
		printf("-- Quest�o 7 \n",setlocale(LC_ALL,""));
		char txt1[100], txt2[100];
		printf("Digite a primeira string: ");
	    scanf("%s", txt1);
	    printf("Digite a segunda string: ");
	    scanf("%s", txt2);
		int checkstrg(char *string1, char *string2) 
		{
			char *p1, *p2;
			while (*string1 != '\0') 
			{
		        p1 = string1;
		        p2 = string2;
		        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) 
				{
		            p1++;
		            p2++;
		        }
		        
		        if (*p2 == '\0') 
				{
		        	return 1;
		        }
		    	string1++;
	    	}
	    return 0; 
		}
		if (checkstrg(txt1, txt2))
		{
			printf("A segunda string ocorre dentro da primeira.\n");
	    }else
		{
	        printf("A segunda string n�o ocorre dentro da primeira.\n");
	    }
	}break;
	
	case 8:
	{	//EXC 8
	 	printf("-- Quest�o 8 \n",setlocale(LC_ALL,""));
		int *v,i;
		v = malloc (5 * sizeof (int));
		printf("Escreva os valores inteiros em cada array: \n", setlocale(LC_ALL,""));
		for(i = 0; i < 5; i++)
		{
			printf("Digite o valor %i: ", i+1);
			scanf("%i", v+i);
		};
		printf("impirmindo o dobro do valor lido:\n");
		for(i = 0; i < 5; i++)
		{
			printf("%i \n",*(v+i) * 2);
		}
	}break;

	case 9:
	{	// EXC 9
		printf("-- Quest�o 9 \nCom suas palavras, descreva o que � um ponteiro em C.\n",setlocale(LC_ALL,""));
		printf("Um ponteiro na linguagem C se trata de uma vari�vel na qual aponta para o endere�o do tipo do qual foi especificado para ela.\nPortanto, conseguimos puxar o endere�o e v�riavel para qual ela aponta assim como modificar os mesmos.");
	}break;
	
	case 10:
	{	//EXC 10
		printf("-- Quest�o 10\n",setlocale(LC_ALL,""));
		//Podemos criar um novo tipo para criar uma estrutura de dado baseada nos tipos prim�rios
		typedef struct {
		    char nome[100];
		    char email[100];
		    char telefone[15];
		    char nascimento[11];
		} aluno;
		//A melhor forma de alocar a mem�ria nas informa��es � criando e redirecionando um ponteiro.
		aluno *ponteiro;
		ponteiro = malloc(sizeof(aluno));
		//Podemos acessar a a parte especfica da estrutura evidenciando ela 
		printf("Digite o nome do aluno: ");
	    scanf("%s", &ponteiro->nome);
	    printf("Digite o email do aluno: ");
	    scanf("%s", &ponteiro->email);
	    printf("Digite o telefone do aluno: ");
	    scanf("%s", &ponteiro->telefone);
	    printf("Digite a data de nascimento do aluno (dd/mm/aaaa): ");
	    scanf("%s", &ponteiro->nascimento);
	    //Podemos mostrar as partes espec�ficas da mesma forma
	    printf("\nDados do aluno:\n");
	    printf("Nome: %s\n", ponteiro->nome);
	    printf("Email: %s\n", ponteiro->email);
	    printf("Telefone: %s\n", ponteiro->telefone);
	    printf("Data de Nascimento: %s\n", ponteiro->nascimento);
	    //Para excluir o dado da mem�ria
		free(ponteiro);	    
	}break;
	default: return(0);
	}; 
	printf("\nDeseja ver outra quest�o?");
	scanf("%i", &esc);
}while (esc < 11);
	return EXIT_SUCCESS;
}
