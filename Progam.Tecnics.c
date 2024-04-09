#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int h, c, linha, espaco, area = 0;
	printf("Defina a altura do triângulo: \n",setlocale(LC_ALL,""));
	scanf("%i", &h);
	
	if (h < 0){
		printf("insira um valor válido");
		
	} else {
		for(linha = 0; linha < h; linha++) {
	        for(espaco = 0; espaco <= linha; espaco++) {
	            printf("* ");
	            area++;
	        }
	        printf("\n");
	    };
	    printf("%i", area);
	};

}
