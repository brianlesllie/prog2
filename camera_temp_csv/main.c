/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string>
  */ 
  
#include <stdio.h>


struct dado_t {
    int amostra;
    float temperatura;
    char tempo[64];
}


int main(){
    int i;
    int n_linhas = 0;
    char *info;
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

    /* Aloque memória:
    dados = malloc(sizeof(struct dado_t) * n_linhas); */
    
    rewind(fp);
     /* Ignora primeira linha */
    fgets(info,64, fp);
    
    /* Modifique aqui para colocar os dados no vetor 
     * de estruturas alocado  dinamicamente *
     * ex: dados[i].amostra = amostra; */
     
    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, data) == 3){
       printf("%d, %f, %s\n", amostra, temperatura, data);
    }


    /* Imprima os dados:*/
    for (i=0; i < n_linhas; i++){
        //printf( "...", dados[i].amostra, ... );
    }


    fclose(fp);
}
