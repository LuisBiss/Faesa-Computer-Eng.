#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX_ATV 100

void add_atv()
{
	
	char atv[MAX_ATV];
	char data[12];
	FILE *arq;
	printf("Digite a descrição da tarefa: ",setlocale(LC_ALL,""));
	fgets(atv, MAX_ATV, stdin);
	printf("Digite a data da tarefa (DD/MM/AAAA): ");
	scanf("%s",data);
	arq = fopen("atividades.txt", "a+");
	if (arq == NULL) 
	{
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arq, "%s --- %s\n", data, atv);
    fclose(arq);
    printf("Tarefa adicionada com sucesso!\n");
}

void show_atv() 
{
    char data_hoje[11]; 
    char linha[200];
    FILE *arq;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t); //Pegar o dia pelo sistema

    sprintf(data_hoje, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900); //Stringfy a data no valor certo

    arq = fopen("atividades.txt", "r");
    if (arq == NULL) 
	{
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    printf("Tarefas para hoje (%s):\n", data_hoje);
    while (fgets(linha, sizeof(linha), arq) != NULL)  //Sem usar EOF
	{
        if (strstr(linha, data_hoje) != NULL) // strstr retorna null se uma string conter a outra
		{
            printf("%s \n", linha);
        }
    }
    fclose(arq);
}

void esp_dat() 
{
	char data[12]; 
    char linha[200];
    FILE *arq;
    printf("\nEscreva a data que deseja veririfar as tarefas:");
    scanf("%s",data);
    arq = fopen("atividades.txt", "r");
    if (arq == NULL) 
	{
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    printf("Tarefas do dia %s:\n",data);
    while (fgets(linha, sizeof(linha), arq) != NULL)
	{
        if (strstr(linha, data) != NULL)
		{
            printf("%s \n", linha);
        } 
    }
    fclose(arq);
}

void all_atv()
{
	char linha[200];
    FILE *arq;
    arq = fopen("atividades.txt", "r");
	  while (fgets(linha, sizeof(linha), arq) != NULL)
	{
		printf("%s", linha);
	}
	fclose(arq);
}
int main() 
{
    int opcao;
    char continuar;
	printf("\nBem Vindo!! \n",setlocale(LC_ALL,""));
    do {
        printf("\n ----- Sistema de Arquivamento de Tarefas -----\n 1. Adicionar uma nova tarefa\n 2. Mostrar as tarefas do dia\n 3. Ver tarefas de um dia\n 4. Ver todas as atividades\n Digite o número da opção desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                add_atv();
                break;
            case 2:
            	show_atv();
                break;
            case 3:
                esp_dat();
                break;
            case 4:
            	all_atv();
            	break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("\nDeseja continuar (s/n)? ");
        scanf(" %c", &continuar);
    } while (continuar == 's' );

   return EXIT_SUCCESS;
}
