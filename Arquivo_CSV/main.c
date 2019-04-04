#include <stdio.h>

#include "lista_enc.h"

/* Demais includes */


int main(){
    
    /* Variáveis */
    lista_enc_t *minha_lista;
    
    minha_lista = ler_arquivo("dados.csv");
    
    imprimi_dados_lista(minha_lista);
    
    // libera_dados(minha_lista);
    
    return 0;
}
