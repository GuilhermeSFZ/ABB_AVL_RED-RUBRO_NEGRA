#include "avl.h"
#include <math.h>
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

int altura_NO(tipo_noh_avl *no) {
    if (no == NULL)
        return -1;
    else
        return no->h;
}

int maior(int x, int y) {
    return (x > y) ? x : y;
}

int fatorBalanceamento_NO(tipo_noh_avl *no) {
    return (altura_NO(no->dir) - altura_NO(no->esq));
}

tipo_noh_avl *rotacao_direita(tipo_noh_avl *pt, int *rotacoes) {
    tipo_noh_avl *ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;

    // Atualiza alturas
    pt->h = maior(altura_NO(pt->esq), altura_NO(pt->dir)) + 1;
    ptu->h = maior(altura_NO(ptu->esq), pt->h) + 1;

    // Atualiza contador de rotações
    (*rotacoes)++;

    return ptu;
}

tipo_noh_avl *rotacao_esquerda(tipo_noh_avl *pt, int *rotacoes) {
    tipo_noh_avl *ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;

    // Atualiza alturas
    pt->h = maior(altura_NO(pt->esq), altura_NO(pt->dir)) + 1;
    ptu->h = maior(altura_NO(ptu->dir), pt->h) + 1;

    // Atualiza contador de rotações
    (*rotacoes)++;

    return ptu;
}

tipo_noh_avl *rotacao_dupla_direita(tipo_noh_avl *pt, int *rotacoes) {
    pt->esq = rotacao_esquerda(pt->esq, rotacoes);
    pt = rotacao_direita(pt, rotacoes);
    return pt;
}

tipo_noh_avl *rotacao_dupla_esquerda(tipo_noh_avl *pt, int *rotacoes) {
    pt->dir = rotacao_direita(pt->dir, rotacoes);
    pt = rotacao_esquerda(pt, rotacoes);
    return pt;
}


tipo_noh_avl *insereAVL(tipo_noh_avl *no, int chave, int *rotacoes) {
    tipo_noh_avl *u;

    if (no == NULL) {
        no = (tipo_noh_avl *)malloc(sizeof(tipo_noh_avl));
        no->chave = chave;
        no->esq = no->dir = NULL;
        no->h = 0;
        no->fb = 0;
    } else if (chave < no->chave) {
        no->esq = insereAVL(no->esq, chave, rotacoes);
        no->h = maior(altura_NO(no->esq), altura_NO(no->dir)) + 1;
        no->fb = fatorBalanceamento_NO(no);

        if (no->fb <= -2) {
            u = no->esq;
            u->fb = fatorBalanceamento_NO(u);

            if (u->fb == -1) {
                no = rotacao_direita(no, rotacoes);
            } else {
                no = rotacao_dupla_direita(no, rotacoes);
            }
        }
    } else if (chave > no->chave) {
        no->dir = insereAVL(no->dir, chave, rotacoes);
        no->h = maior(altura_NO(no->esq), altura_NO(no->dir)) + 1;
        no->fb = fatorBalanceamento_NO(no);

        if (no->fb == 2) {
            u = no->dir;
            u->fb = fatorBalanceamento_NO(u);

            if (u->fb == 1) {
                no = rotacao_esquerda(no, rotacoes);
            } else {
                no = rotacao_dupla_esquerda(no, rotacoes);
            }
        }
    } else {
        printf("Inserção inválida: chave %d já existe\n", chave);
        exit(1);
    }

    return no;
}


int buscaAVL(tipo_noh_avl *no, int chave, int *comparacoes) {
    if (no == NULL) {
        return 0; // Retorna 0 (false) se o nó for NULL (não encontrado)
    }

    (*comparacoes)++; // Incrementa o contador de comparações

    if (chave == no->chave) {
        return 1; // Retorna 1 (true) se a chave for encontrada
    } else if (chave < no->chave) {
        return buscaAVL(no->esq, chave, comparacoes); // Procura na subárvore esquerda
    } else {
        return buscaAVL(no->dir, chave, comparacoes); // Procura na subárvore direita
    }
}

void le_arquivoAVL(const char *arq, tipo_noh_avl **no, int *rotacoes) {
    int num;
    FILE *file = fopen(arq, "r");
    if (file == NULL) {
        printf("[ERRO] não foi possível abrir o arquivo!");
        exit(1);
    }
    while (fscanf(file, "%d", &num) != EOF) {
        *no = insereAVL(*no, num, rotacoes);
    }
    fclose(file);
}

void busca_avl(tipo_noh_avl *arvore, int *valores, int tam, int *total_comparacoes, double *total_tempo) {
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
        int sucesso = buscaAVL(arvore, valores[i], &comparacoes); // Atualiza comparacoes
        end_time = times(&end); // Termina a medição

        *total_comparacoes += comparacoes;
        *total_tempo += (end_time - start_time) / (double)sysconf(_SC_CLK_TCK); // Calcula o tempo gasto
    }
}