#ifndef __ARVBB__
#define __ARVBB__
#include <stdio.h>
#include <stdlib.h>

struct est_noh
{
    int dado;
    struct est_noh *esq;
    struct est_noh *dir;
}; typedef struct est_noh tipo_noh_arv;

//Definição dos protótipos
tipo_noh_arv *alocaNoh(int);
void insercaoArvBin(tipo_noh_arv **, int);
int buscaValor(tipo_noh_arv *, int, int*);
int alturaArvore(tipo_noh_arv *);
void le_arquivoABB(const char *arq,tipo_noh_arv **no);
void busca_abb(tipo_noh_arv *arvore, int *valores, int tam, int *total_comparacoes, double *total_tempo);
#endif