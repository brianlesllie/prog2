#ifndef DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra 
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char * timestamp);
dado_t **ler_dados_csv(char *nome_do_arquivo, int *n_linhas);

/* Outras funções aqui: fazer os comentários */
int obter_amostra(dado_t **dado, int i);
float obter_temperatura(dado_t **dado, int i);
char *obter_tempo(dado_t **dado, int i);

void liberar_dados(dado_t **vetor, int n_linhas);

#endif
