/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string>
  */

#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

int main(){
    int i=0;
    int n_linhas = 0;

    int amostra;
    float temperatura;
    char *tempo;

    dado_t **dado=ler_dados_csv("camera_temp.csv",&n_linhas);
    /* Imprima os dados:*/
    for (i=0; i < n_linhas; i++){
    	amostra=obter_amostra(dado,i);
    	temperatura=obter_temperatura(dado,i);
    	tempo=obter_tempo(dado,i);
    	printf( "%d,%f,%s\n", amostra, temperatura,tempo);
    }


    liberar_dados(dado,n_linhas);

    return 0;
}
