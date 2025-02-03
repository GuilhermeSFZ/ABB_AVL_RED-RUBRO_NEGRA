#include "rubro_negra.h"
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

int cor(TNoA *noh) {
    return (noh == NULL) ? BLACK : noh->cor;
}

TNoA *rotacao_dir(TNoA *pt, int *rotacoes) {
    TNoA *ptu = pt->esq;

    pt->esq = ptu->dir;
    if (ptu->dir != NULL)
        ptu->dir->pai = pt;
    ptu->pai = pt->pai;

    if (pt->pai != NULL) {
        if (pt == pt->pai->dir)
            pt->pai->dir = ptu;
        else
            pt->pai->esq = ptu;
    } else {
        ptu->pai = NULL;
    }
    ptu->dir = pt;
    pt->pai = ptu;
    (*rotacoes)++;
    return ptu;
}

TNoA *rotacao_esq(TNoA *pt, int *rotacoes) {
    TNoA *ptu = pt->dir;

    pt->dir = ptu->esq;
    if (ptu->esq != NULL)
        ptu->esq->pai = pt;
    ptu->pai = pt->pai;

    if (pt->pai != NULL) {
        if (pt == pt->pai->esq)
            pt->pai->esq = ptu;
        else
            pt->pai->dir = ptu;
    } else {
        ptu->pai = NULL;
    }
    ptu->esq = pt;
    pt->pai = ptu;
    (*rotacoes)++;
    return ptu;
}

TNoA *insere_fixup(TNoA *T, TNoA *z, int *rotacoes) {
    TNoA *y;
    while (cor(z->pai) == RED) {
        if (z->pai == z->pai->pai->esq) {
            y = z->pai->pai->dir;
            if (cor(y) == RED) {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            } else {
                if (z == z->pai->dir) {
                    z = z->pai;
                    rotacao_esq(z, rotacoes);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED;
                rotacao_dir(z->pai->pai, rotacoes);
            }
        } else {
            y = z->pai->pai->esq;
            if (cor(y) == RED) {
                z->pai->cor = BLACK;
                y->cor = BLACK;
                z->pai->pai->cor = RED;
                z = z->pai->pai;
            } else {
                if (z == z->pai->esq) {
                    z = z->pai;
                    rotacao_dir(z, rotacoes);
                }
                z->pai->cor = BLACK;
                z->pai->pai->cor = RED;
                rotacao_esq(z->pai->pai, rotacoes);
            }
        }
    }
    while (z->pai != NULL) {
        z = z->pai;
    }
    z->cor = BLACK;
    return z;
}

TNoA *insere(TNoA *no, int chave, int *rotacoes) {
    TNoA *y = NULL;
    TNoA *x = no;

    while (x != NULL) {
        y = x;
        if (chave < x->chave)
            x = x->esq;
        else
            x = x->dir;
    }

    x = (TNoA *)malloc(sizeof(TNoA));
    x->chave = chave;
    x->esq = x->dir = NULL;
    x->cor = RED;
    x->pai = y;
    if (y == NULL) {
        no = x;
    } else {
        if (x->chave < y->chave)
            y->esq = x;
        else
            y->dir = x;
    }

    x = insere_fixup(no, x, rotacoes);

    return x;
}

int buscaRN(TNoA *no, int chave, int *comparacoes) {

    while (no != NULL) {
        (*comparacoes)++; // Incrementa o valor apontado por comparacoes
        if (no->chave == chave) {
            return 1;
        }
        if (chave < no->chave)
            no = no->esq;
        else
            no = no->dir;
    }
    return 0;
}

int alturaRN(TNoA *raiz) {
    int dir, esq;
    if (raiz == NULL)
        return 0;
    else {
        esq = alturaRN(raiz->esq);
        dir = alturaRN(raiz->dir);
        return ((esq > dir) ? esq : dir) + 1;
    }
}

void le_arquivoRN(const char *arq, TNoA **no, int *rotacoes) {
    int num;
    FILE *file = fopen(arq, "r");
    if (file == NULL) {
        printf("[ERRO] não foi possivel abrir o arquivo!");
        exit(1);
    }
    while (fscanf(file, "%d", &num) != EOF) {
        *no = insere(*no, num, rotacoes);
    }
    fclose(file);
}

// Função para medir o tempo e contagem de comparações na árvore Rubro-Negra
void busca_rubro_negra(TNoA *arvore, int *valores, int tam, int *total_comparacoes, double *total_tempo) {
    // Verifica se a árvore e os valores não são nulos
    if (arvore == NULL || valores == NULL) {
        printf("Erro: Árvore ou valores são nulos.\n");
        return;
    }

    struct tms start, end;
    clock_t start_time, end_time;
    int comparacoes;
    int num_buscas = tam * 0.2; // Calcula o número de buscas (20% do total)

    *total_comparacoes = 0;
    *total_tempo = 0.0;

    for (int i = 0; i < num_buscas; i++) {
        start_time = times(&start); // Começa a medir o tempo de CPU
        comparacoes = 0;
        int sucesso = buscaRN(arvore, valores[i], &comparacoes); // Atualiza comparacoes
        end_time = times(&end); // Termina a medição

        *total_comparacoes += comparacoes;
        *total_tempo += (end_time - start_time) / (double)sysconf(_SC_CLK_TCK); // Calcula o tempo gasto
    }
}