
/* de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string> */
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "dados.h"
#include "no.h"
  
struct dados {
    int amostra;        /*!< Identificador numérido da amostra */
    float temperatura;  /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};


float temperatura_media(lista_enc_t *lista){
    /* Implemente aqui */
	int tam;
	dado_t *dado;
	float temp_med=0,temp;
	no_t *meu_no;
	//no_t *prox_no;                  //Variável desnecessária
	meu_no=obter_cabeca(lista);
	while(meu_no!=NULL){
		dado=obter_dado(meu_no);
		temp=obter_temperatura(dado);
		temp_med=temp_med+temp;
		//prox_no=obter_proximo(meu_no);
		//meu_no=prox_no;
		meu_no=obter_proximo(meu_no);
	}
	tam=obter_tamanho(lista);
	temp_med=temp_med/tam;
	return temp_med;
}



float temperatura_max(lista_enc_t *lista){
    /* Implemente aqui */
	dado_t *dado;
	float temp_max,temp;        //temp_max deve ser inicilizado!
	temp_max=-10000000000;
	no_t *meu_no;
	//no_t *prox_no;              // variável desnecessária
	meu_no=obter_cabeca(lista);
	dado=obter_dado(meu_no);
	temp=obter_temperatura(dado);
	temp_max=temp;
	while(meu_no!=NULL){
		dado=obter_dado(meu_no);
		temp=obter_temperatura(dado);
		if(temp>temp_max){
			temp_max=temp;
		}
		//temp_med=temp_med+temp;
		//ox_no=obter_proximo(meu_no);
		//u_no=prox_no;
		meu_no=obter_proximo(meu_no);
	}
	//tam=obter_tamanho(lista);
	//temp_med=temp_med/tam;
	return temp_max;
}


void liberar_dados(lista_enc_t *lista){
    /* Implemente aqui */
    no_t *no=obter_cabeca(lista);
	no_t *no_prox;
	while(no!=NULL){
		free(obter_dado(no));
		no_prox=obter_proximo(no);
		free(no);
		no=no_prox;
	}
	free(lista);
}



dado_t * criar_dado (int amostra, float temperatura, char * timestamp){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    meu_novo_dado->amostra = amostra;
    meu_novo_dado->temperatura = temperatura;
    strncpy(meu_novo_dado->tempo, timestamp, 64);
    
    return meu_novo_dado;
}



lista_enc_t *ler_dados_csv(char *nome_do_arquivo){
    char texto[64];
    int amostra;
    float temperatura;

    /* Demais Variáveis */
    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    lista = criar_lista_enc();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */
    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3){
        
#ifdef DEBUG
    	printf("Lido %d, %f, %s\n", amostra, temperatura, texto);
#endif
        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(amostra, temperatura, texto);
        meu_no = criar_no(dado);
        add_cauda(lista, meu_no);
    }

    fclose(fp);

    return lista;
}

float obter_temperatura(dado_t *dado){
    return dado->temperatura;
}

void imprimir_dados(lista_enc_t *lista){

	no_t *no;

	/* Imprime dados de toda a lista */
	for (no=obter_cabeca(lista); no != NULL; no=obter_proximo(no)){
		dado_t *dado = obter_dado(no);
		printf("%d\t%f\t%s\n", dado->amostra, dado->temperatura, dado->tempo);
	}
}
