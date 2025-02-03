#include "arvbb.h"
#include <sys/times.h>
#include <sys/types.h>
#include <unistd.h>

tipo_noh_arv *alocaNoh(int valor) {
    tipo_noh_arv *novo_noh = (tipo_noh_arv *)malloc(sizeof(tipo_noh_arv));
    novo_noh->dado = valor;
    novo_noh->dir = NULL;
    novo_noh->esq = NULL;
    return novo_noh;
}

void insercaoArvBin(tipo_noh_arv **nohArv, int valor) {
    if ((*nohArv) == NULL) {
        (*nohArv) = alocaNoh(valor);
    } else {
        if (valor < (*nohArv)->dado) {
            insercaoArvBin(&(*nohArv)->esq, valor);
        } else {
            insercaoArvBin(&(*nohArv)->dir, valor);
        }
    }
}

int buscaValor(tipo_noh_arv *nohArv, int valor, int *comparacoes) {
    if (nohArv == NULL) {
        return 0; // Retorna 0 para indicar que o valor não foi encontrado
    }

    (*comparacoes)++; // Contabiliza a comparação com o valor atual

    if (valor == nohArv->dado) {
        return 1; // Valor encontrado
    } else if (valor < nohArv->dado) {
        return buscaValor(nohArv->esq, valor, comparacoes); // Procura na subárvore esquerda
    } else {
        return buscaValor(nohArv->dir, valor, comparacoes); // Procura na subárvore direita
    }
}


int alturaArvore(tipo_noh_arv *nohArv) {
    if (nohArv == NULL)
        return 0;
    int altEsq = alturaArvore(nohArv->esq);
    int altDir = alturaArvore(nohArv->dir);
    return (altEsq > altDir ? altEsq : altDir) + 1;
}



void le_arquivoABB(const char *arq, tipo_noh_arv **no) {
    int num;
    FILE *file = fopen(arq, "r");
    if (file == NULL) {
        printf("[ERRO] não foi possível abrir o arquivo!");
        exit(1);
    }
    while (fscanf(file, "%d", &num) != EOF) {
        insercaoArvBin(no, num);
    }
    fclose(file);
}

void busca_abb(tipo_noh_arv *arvore, int *valores, int tam, int *total_comparacoes, double *total_tempo) {
    struct tms start, end;
    clock_t start_time, end_time;
    int comparacoes;

    *total_comparacoes = 0;
    *total_tempo = 0.0;

    for (int i = 0; i < 0.2 * tam; i++) {
        start_time = times(&start); // Começa a medir o tempo de CPU
        comparacoes = 0;
        buscaValor(arvore, valores[i], &comparacoes); // Atualiza comparacoes
        end_time = times(&end); // Termina a medição

        *total_comparacoes += comparacoes;
        *total_tempo += (end_time - start_time) / (double)sysconf(_SC_CLK_TCK); // Calcula o tempo gasto
    }
}