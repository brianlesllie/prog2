/*
 ============================================================================
 Name        : cam_temp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string>
  */

#include <stdio.h>
#include <stdlib.h>

struct dado_t {
    int amostra;
    float temperatura;
    char tempo[64];
};


int main(){
    int i=0;
    int n_linhas = 0;
    char info[64];
    /* Ponteiro para alocação dinâmica dos dados */
    struct dado_t *dados = NULL;

    FILE *fp = fopen("camera_temp.csv","r");

    if (!fp){
        perror("main");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(info,64, fp);

    /* Contar todas as linhas: use while e fgets() */
    while ( fgets(info, 64, fp) != NULL){
       n_linhas++;
    }

    /* Aloque memória: */
    dados = malloc(sizeof(struct dado_t) * n_linhas);

    rewind(fp);
     /* Ignora primeira linha */
    fgets(info,64, fp);

    /* Modifique aqui para colocar os dados no vetor
     * de estruturas alocado  dinamicamente *
     * ex: dados[i].amostra = amostra; */

    while (fscanf (fp, "%d,%f,%63[^\n]", &dados[i].amostra, &dados[i].temperatura, dados[i].tempo) == 3){
       //printf("%d, %f, %s\n", dados[i].amostra, dados[i].temperatura, dados[i].tempo);
       i++;
    }


    /* Imprima os dados:*/
    for (i=0; i < n_linhas; i++){
    	printf("%d, %f, %s\n", dados[i].amostra, dados[i].temperatura, dados[i].tempo);
    }


    fclose(fp);
    free(dados);

    return 0;
}
