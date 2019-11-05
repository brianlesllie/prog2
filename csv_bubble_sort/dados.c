
/* de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string> */
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
struct dados {
    int amostra;        /*!< Identificador numérido da amostra */
    float temperatura;  /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};


dado_t * criar_dado (int amostra, float temperatura, char * tempo){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    
    // Colocar a criação dos dados aqui
    meu_novo_dado->amostra=amostra;
    meu_novo_dado->temperatura=temperatura;
    strcpy(meu_novo_dado->tempo,tempo);

    
    return meu_novo_dado;
}



dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas){
    char texto[64];
    int i=0;
    /* Demais Variáveis */
    int amostra;
    float temperatura;
    char tempo[64];
    
    dado_t **dados;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Contar todas as linhas: use while e fgets() */
    while ( fgets(tempo, 64, fp) != NULL){
       n_linhas++;
    }
    
    

    /* Aloque memória: 
     * Agora é um vetor de ponteiros */
    dados = malloc(sizeof(dado_t) *(*n_linhas));
    
    rewind(fp);
     /* Ignora primeira linha */
    fgets(texto,64, fp);
    

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3){
        printf("Lido %d, %f, %s\n", amostra, temperatura, tempo);
        
        /* Cria um novo dado abstrato e armazena a sua referência */
        dados[i] = criar_dado(amostra, temperatura, tempo);
    
        i++;
    }
    
    return dados;
}



void liberar_dados(dado_t **vetor, int n_linhas){
    int i;
    for(i=0;i<n_linhas;i++){
    	free(vetor[i]);
    }
    free(vetor);
}

int obter_amostra(dado_t **dado, int i){
    return (dado[i]->amostra);
}
float obter_temperatura(dado_t **dado, int i){
    return dado[i]->temperatura;
}
char *obter_tempo(dado_t **dado, int i){
    return dado[i]->tempo;
}

