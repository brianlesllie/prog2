/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void) {


	int i,j;
	grafo_t *g;

    /* Cria grafo com 20 vértices */
	g = cria_grafo(8);

	/*    Adicionar arestas    */
	cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 0, 2);
	cria_adjacencia(g, 1, 2);
	cria_adjacencia(g, 1, 3);
	cria_adjacencia(g, 1, 4);
	cria_adjacencia(g, 2, 4);
	cria_adjacencia(g, 2, 6);
	cria_adjacencia(g, 2, 7);
	cria_adjacencia(g, 3, 4);
	cria_adjacencia(g, 4, 5);
	cria_adjacencia(g, 6, 7);

	//grafo->vertices[i].dist=-1;
	//grafo->vertices[i].pai=NULL;
	
	/* Imprime matriz */
	for (i=0; i < 8; i++){
		for (j=0; j < 8; j++)
			printf("[%d] [%d] : %d\n", i+1,j+1, adjacente(g,i,j));
	}



	libera_grafo(g);

	return EXIT_SUCCESS;
}
