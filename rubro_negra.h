#ifndef __RUBRO_NEGRA__
#define __RUBRO_NEGRA__
#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1


typedef struct sNoA
{
    int chave;
    int cor;
    struct sNoA *esq;
    struct sNoA *dir;
    struct sNoA *pai;
} TNoA;

int cor(TNoA *noh);
TNoA *rotacao_dir(TNoA *pt, int*);
TNoA *rotacao_esq(TNoA *pt, int*);
TNoA *insere_fixup(TNoA *T, TNoA *z, int *);
TNoA *insere(TNoA *no, int chave, int *);
int buscaRN(TNoA *no, int chave, int *);
int alturaRN(TNoA *raiz);
void le_arquivoRN(const char *arq, TNoA **no, int *);
void busca_rubro_negra(TNoA *arvore, int *valores, int tam, int *total_comparacoes, double *total_tempo);
#endif