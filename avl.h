#ifndef __AVL__
#define __AVL__
#include <stdio.h>
#include <stdlib.h>

typedef struct est_nohAvl
{
    int chave;
    int fb; // fator de balanceamento
    int h;
    struct est_nohAvl *esq;
    struct est_nohAvl *dir;
} tipo_noh_avl;

int altura_NO(tipo_noh_avl *no);
int maior(int x, int y);
int fatorBalanceamento_NO(tipo_noh_avl *no);
tipo_noh_avl *rotacao_direita(tipo_noh_avl *pt, int*);
tipo_noh_avl *rotacao_esquerda(tipo_noh_avl *pt, int*);
tipo_noh_avl *rotacao_dupla_direita(tipo_noh_avl *pt, int*);
tipo_noh_avl *rotacao_dupla_esquerda(tipo_noh_avl *pt, int*);
tipo_noh_avl *insereAVL(tipo_noh_avl *no, int chave, int*);
int buscaAVL(tipo_noh_avl *, int, int *);
void le_arquivoAVL(const char *arq,tipo_noh_avl **no, int*);
void busca_avl(tipo_noh_avl *arvore, int *valores, int tam, int *total_comparacoes, double *total_tempo);
#endif