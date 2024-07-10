// Biblioteca usada principalmente para funções de entrada e saída: printf() e scanf().
#include <stdio.h>
// Bilioteca que permite o uso de funções de alocação de memória como a função malloc() e das funções rand(), srand() e qsort().
#include <stdlib.h>
// Biblioteca para usar caracteres especiais/acentos. Permite usar a função setlocale().
#include <locale.h>
// Biblioteca para usar as funções matemáticas pow() e sqrt(). Pow é responsável por determinar uma potência em que é usada da seguinte forma: pow(base, expoente). Já a função sqtr é utilizada para calcular a raiz quadrada de um número. Square root
#include <math.h>
// Biblioteca que permite a manipulação do tempo e de datas. Permite usar a função time().
#include <time.h>

int i = 0;
// Uso de typedef para atribuir o alias(apelido) ponto à struct. Os campos(fields) da struct são: ID, Px e Py.
typedef struct
{
    int ID;
    float Px;
    float Py;
} ponto;

// Uso de typedef para atribuir o alias(apelido) registro à struct. Os campos(fields) da struct são: Individuo e valor.
typedef struct
{
    // ponteiro para um inteiro.
    int *Individuo;
    float Valor;
} registro;

// Essa função não retorna nada(é do tipo void). Ela inicializa um gerador de números aleatórios(na verdade o número gerado é pseudoaleatório, pois uma semente é gerada dentro de um algoritmo fornecido pela função srand(), disponibilizada dentro da biblioteca stdlib.h) baseado no tempo atual(time(NULL)). Se não usar uma "semente"(seed do s de srand()), os números aleatórios sempre serão os mesmos quando executar o código. Caso não seja colocado o NULL dentro do time(), essa função irá retornar o tempo em segundos desde 1º de janeiro de 1970(marco inicial da era Unix).
void iniciar_funcao_srand()
{
    srand(time(NULL));
}

// Função que retorna um número pseudoaleatório do tipo float dentro de um intervalo mínimo e máximo fornecidos como parâmetros da função. A constante RAND_MAX vale 32767, esse número é definido pela biblioteca stdlib.h. A função rand() retorna um valor de 0 até RAND_MAX, logo depois rand() é dividido por RAND_MAX para a variável escala ser um número entre 0 e 1.
// (maximo - minimo) é a amplitude entre o maior e o menor número.
// escala * (maximo - minimo) ajusta o intervalo para [0, maximo - minimo]
// minimo + escala * (maximo - minimo) ajusta o intervalo para intervalo [minimo, maximo]
// Exemplo para deixar mais claro: se minimo = 1 e maximo = 360 e rand() = 16384, temos que a escala = 16384 / 32767 que é aproximadamente 0.5. O retorno da função gerar_coordenada será 1 + 0.5 * (360-1) que é igual à 180,5, sendo esse número dentro do intervalo [1,360].
float gerar_coordenada(float minimo, float maximo)
{
    float escala = rand() / (float) RAND_MAX;
    return minimo + escala * (maximo - minimo);
}

// Função que retorna as distâncias entre os pontos. As coordenadas são horizontais(a.Px e b.Px) e verticais(a.Py e b.Py).
float calcular_distancia(ponto a, ponto b)
{
    return sqrt(pow(a.Px - b.Px, 2) + pow(a.Py - b.Py, 2));
}

// Função de comparação para ordenação da função qsort(). Essa função retorna um inteiro. Os parâmetros são do tipo "const void *", isto é, são ponteiro que podem apontar para qualquer tipo de dado.
// regA e regB são identificadores de variável que podem refenciar um instância específica da struct. Exemplo: regA.ID = 1;    
// a linha " registro *regA = (registro *)a;" é aconversão do ponteiro genérico "a" para um ponteiro da struct registro("registro *"), para "a" ser tratado com ponteiro da struct "registro". O mesmo vale para "b".
// regA->Valor e regB->Valor são os acessos ao "field" Valor da struct com alias "registro".
// Os retornos possíveis da função são: 
// Se regA->Valor > regB->Valor, então 1 - 0 = 1. Logo "a" é maior que "b", ou seja, "a" deve vir antes de "b" no ordenamento.
// Se regA->Valor < regB->Valor, então 0 - 1 = -1. Logo "a" é menor que "b", ou seja, "a" deve vir depois de "b" no ordenamento.
// Se regA->Valor é igual a regB->Valor, então 0 - 0 = 0. Logo "a" e "b" são iguais e não há preferência no momento da ordenação.
int comparar_registro(const void *a, const void *b)
{
    // cast = conversão explícita.
    registro *regA = (registro *)a;
    registro *regB = (registro *)b;
    // Operadores relacionais em C retornam true(1) ou false(0).
    return (regA->Valor > regB->Valor) - (regA->Valor < regB->Valor);
}

// O primeiro for inicializa e preenche o vetor de inteiros individuo com valores sequenciais de 1 até n. Isso é feito pela expressão individuo[i] = i + 1;. Por exemplo, se n for 10, o vetor individuo será preenchido com os valores {1, 2, 3, ..., 10}.
// O segundo for() embaralha os valores no vetor individuo.
// A linha int j = rand() % n; calcula o resto e garante que esse valor esteja dentro do intervalo [0,n-1].
// algoritmo de Fisher-Yates (também conhecido como Knuth shuffle).
void gerar_individuo(int individuo[], int n)
{
    for (i = 0; i < n; i++) {
        individuo[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        // gera um número entre 0 e n-1
        int j = rand() % n;
        // A variável temporari o armazena temporariamente os valores de cada elemento do array individuo[i] para não ocorrer perda dos dados por sobrescrição de elementos quando o vetor individuo[i] receber individuo[j].
        int temporario = individuo[i];
        individuo[i] = individuo[j];
        individuo[j] = temporario;
    }
}

// Se a função ser executada com sucesso retorna "0" na penúltima linha(return 0;). "int argc" indica o número de argumentos informados, sendo que sempre terá pelo menos uma argumento que é o próprio nome do código a ser executado.  "char *argv[]" é um array de ponteiros que contém os argumentos informados. "argv[0]" é sempre o nome do código a ser executado.
int main(int argc, char *argv[])
{
    // Configuração de localidade para possibilitar o uso de caracteres com acento.
    setlocale(LC_ALL, "");  
    int quantidadePontos, i, j;
    printf("Primeiro escreva com quantos pontos deseja trabalhar (máximo 10):");
    scanf("%d", &quantidadePontos);

    if (quantidadePontos > 10)
    {
        printf("Número máximo de pontos permitido é 10.\n");
        return 1;
    }

    // Declaração de um array com nome "pontos" do tipo ponto que armazena a quantidade "quantidadePontos" de elementos do tipo ponto.
    ponto pontos[quantidadePontos];

    // Inicializa a matriz de distâncias com todos os elementos valendo 0.0.
    float dist[10][10] = {0}; 

    // Criação dos pontos.
    iniciar_funcao_srand();
    for (i = 0; i < quantidadePontos; i++)
    {
        // "pontos[i]" é o array "pontos" na posição "i". ID é o "field" da struct com alias "ponto".
        pontos[i].ID = i;
        // 360 corresponde aos 4 quadrantes do plano cartesiano, cada um com 90 graus de amplitude.
        pontos[i].Px = gerar_coordenada(1, 360);
        pontos[i].Py = gerar_coordenada(1, 360);
        printf("ponto %d: ID -> %d ; Px -> %.2f ; Py -> %.2f \n", i, pontos[i].ID, pontos[i].Px, pontos[i].Py);
    }

    // Calcula a matriz de distâncias.
    for (i = 0; i < quantidadePontos; i++)
    {
        for (j = 0; j < quantidadePontos; j++)
        {
            if (i != j)
            {
                // Matriz com nome dist, [i] e [j] são as posições da linha e coluna, respectivamente.
                dist[i][j] = calcular_distancia(pontos[i], pontos[j]);
            }
        }
    }

    // Imprime a matriz de distâncias com cabeçalhos.
    printf("\nMatriz de Distâncias:\n");

    // Imprime o cabeçalho das colunas.
    // Espaço horizontal para ajustar o cabeçalho das colunas aos respectivos resultados das distâncias.
    printf("       ");
    for (j = 0; j < quantidadePontos; j++)
    {
        printf("   P%d    ", pontos[j].ID);
    }
    printf("\n");

    // Imprime as distâncias com cabeçalho das linhas.
    for (i = 0; i < quantidadePontos; i++)
    {
        printf("P%d  ", pontos[i].ID);
        for (j = 0; j < quantidadePontos; j++)
        {
            if (i != j)
            {
                // 8 é a quantidade de dígitos do número, 2 é a quantidade dígitos após a vírgula.
                printf("%8.2f ", dist[i][j]);
            }
            else
            {
                printf("   0.00   ");
            }
        }
        printf("\n");
    }

    // Construção da população.
    // Declaração de um array com nome "população" do tipo registro que armazena a quantidade de 100 elementos do tipo registro.
    registro populacao[100];

    for (i = 0; i < 100; i++)
    {
        // malloc() aloca a quantidade específica de memória e sizeof(int) retorna o número de bytes necessário para armazenar um inteiro.
        populacao[i].Individuo = malloc(quantidadePontos * sizeof(int));
        // Preeche o ponteiro "populacao[i].Individuo" do array populacao com números de 1 até  a quantidade de pontos inseridos pelo usuário, sem repetições.
        gerar_individuo(populacao[i].Individuo, quantidadePontos);
        // Calcula o valor do custo da rota(somatório das distâncias).
        // ampo do tipo float que pertence à estrutura registro na posição i do vetor populacao.
        populacao[i].Valor = 0;
        for (j = 0; j < quantidadePontos - 1; j++)
        {
            // Corresponde ao ponto inicial da aresta atual. É subtraído 1 para obter o índice do vetor que começa na posição 0.
            int inicio = populacao[i].Individuo[j] - 1;
            // O j+1 indica o próximo ponto do trajeto e a subtração de 1 é para obter o índice correto.
            int fim = populacao[i].Individuo[j + 1] - 1;
            // incremento da distância ao campo Valor.
            populacao[i].Valor += dist[inicio][fim];
        }
        // Adiciona a volta ao ponto inicial
        int indiceUltimoPonto = populacao[i].Individuo[quantidadePontos - 1] - 1;
        int indicePrimeiroPonto = populacao[i].Individuo[0] - 1;
        populacao[i].Valor += dist[indiceUltimoPonto][indicePrimeiroPonto];
    }

    // Ordena a população pelo campo valor.
    // populacao é o vetor que deseja-se ordenar, 100 indica a quantidade de elementos desse vetor que serão ordenados, o terceiro argumento faz referência ao tamanho em bytes de cada elemento do vetor. Exemplo: Individuo[10] é um vetor com 10 elementos inteiros e cada "int" ocupa 4 bytes, logo o vetor Individuo[10] ocupará 40 bytes. Já o campo Valor é do tipo float, ocupando 4 bytes. Desse modo, cada elemento do vetor população irá ocupar 44 bytes na memória.
    // O 4º parâmetro é a função definida para ordenar os elementos.
    qsort(populacao, 100, sizeof(registro), comparar_registro);

    // Imprime a população ordenada
    printf("\nPopulação Ordenada pelo Valor:\n");
    for (i = 0; i < 100; i++)
    {
        printf("Indivíduo %d: [", i + 1);
        for (j = 0; j < quantidadePontos; j++)
        {
            //  populacao[i] é um vetor que acessa a posição i, já populacao[i].Individuo acessa o ponteiro Individuo que aponta para números inteiros e é da instância da struct registro.
            printf("%d", populacao[i].Individuo[j]);
            // Se não for o último elemento do vetor Indivíduo[], uma vírgula é acrescentada.
            if (j < quantidadePontos - 1)
                printf(", ");
        }
        printf("] - Valor: %.2f\n", populacao[i].Valor);
    }

    return 0;
}
