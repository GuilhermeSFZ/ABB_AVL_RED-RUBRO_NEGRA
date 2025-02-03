#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "rubro_negra.h"
#include "arvbb.h"
#include <sys/times.h> 
#include <sys/types.h>
#include <unistd.h>
//Protótipos
void gerar_dados(int vlr, const char *nome_arq);
void seleciona_20porcento(const char *nome_arq, int **num, int tam);

int main()
{
    //CRIAÇÃO DA LISTA-----------------------------------------------------------------------------------------
    TNoA *minhaArvRN1;
    TNoA *minhaArvRN2;
    TNoA *minhaArvRN3;
    TNoA *minhaArvRN4;
    TNoA *minhaArvRN5;
    TNoA *minhaArvRN6;
    
    tipo_noh_arv *minhaArvBB1;
    tipo_noh_arv *minhaArvBB2;
    tipo_noh_arv *minhaArvBB3;
    tipo_noh_arv *minhaArvBB4;
    tipo_noh_arv *minhaArvBB5;
    tipo_noh_arv *minhaArvBB6;

    tipo_noh_avl *minhaArvAVL1;
    tipo_noh_avl *minhaArvAVL2;
    tipo_noh_avl *minhaArvAVL3;
    tipo_noh_avl *minhaArvAVL4;
    tipo_noh_avl *minhaArvAVL5;
    tipo_noh_avl *minhaArvAVL6;


    minhaArvRN1 = NULL;
    minhaArvRN2 = NULL;
    minhaArvRN3 = NULL;
    minhaArvRN4 = NULL;
    minhaArvRN5 = NULL;
    minhaArvRN6 = NULL;
    
    minhaArvBB1 = NULL;
    minhaArvBB2 = NULL;
    minhaArvBB3 = NULL;
    minhaArvBB4 = NULL;
    minhaArvBB5 = NULL;
    minhaArvBB6 = NULL;

    minhaArvAVL1 = NULL;
    minhaArvAVL2 = NULL;
    minhaArvAVL3 = NULL;
    minhaArvAVL4 = NULL;
    minhaArvAVL5 = NULL;
    minhaArvAVL6 = NULL;
    
    //Definição dos contadores das rotacoes de AVL e RN
    int rotacoesAVL1, rotacoesAVL2, rotacoesAVL3, rotacoesAVL4, rotacoesAVL5, rotacoesAVL6;
    int rotacoesRN1, rotacoesRN2, rotacoesRN3, rotacoesRN4, rotacoesRN5, rotacoesRN6;

    rotacoesAVL1 = 0, rotacoesAVL2 = 0, rotacoesAVL3 = 0, rotacoesAVL4 = 0, rotacoesAVL5 = 0, rotacoesAVL6 = 0;
    rotacoesRN1 = 0, rotacoesRN2 = 0, rotacoesRN3 = 0, rotacoesRN4 = 0, rotacoesRN5 = 0, rotacoesRN6 = 0;

    printf("===========================================================================================\n");
    printf("                    Trabalho de Analise de Arvore Binarias Balanceadas\n");
    
    //Chamando a funcao para gerar os arquivos e gravar os numeros aleatoriamente! 
    int tam[] = {5000, 20000};
    const char *nomes[] = {"arqABB", "arqRN", "arqAVL"};
    for(int i = 0; i < 2; i++) { // Para tamanhos 5000 e 20000
        for(int j = 0; j < 3; j++) { // Para cada tipo de árvore
            for(int k = 1; k <= 3; k++) { // Para criar os 3 arquivos de 5k e 20k de cada estrutura de dados;
                char nome_arq[50];
                // Formata o nome do arquivo. Ex.: arqABB1_5000.txt
                sprintf(nome_arq, "%s%d_%d.txt", nomes[j], k, tam[i]);
                gerar_dados(tam[i], nome_arq);
            }
        }
    }
    
    //Leitura dos arquivos
    struct timeval tempo_inicio, tempo_fim;
    double tempo_insercao;

    // Medindo tempo de inserção para ABB
    gettimeofday(&tempo_inicio, NULL);
    le_arquivoABB("arqABB1_5000.txt", &minhaArvBB1);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (ABB1-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoABB("arqABB2_5000.txt", &minhaArvBB2);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (ABB2-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoABB("arqABB3_5000.txt", &minhaArvBB3);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (ABB3-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoABB("arqABB1_20000.txt", &minhaArvBB4);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (ABB1-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoABB("arqABB2_20000.txt", &minhaArvBB5);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (ABB2-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoABB("arqABB3_20000.txt", &minhaArvBB6);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (ABB3-20000): %.6f segundos\n", tempo_insercao);

    // Medindo tempo de inserção para AVL
    gettimeofday(&tempo_inicio, NULL);
    le_arquivoAVL("arqAVL1_5000.txt", &minhaArvAVL1, &rotacoesAVL1);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (AVL1-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoAVL("arqAVL2_5000.txt", &minhaArvAVL2, &rotacoesAVL2);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (AVL2-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoAVL("arqAVL3_5000.txt", &minhaArvAVL3, &rotacoesAVL3);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (AVL3-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoAVL("arqAVL1_20000.txt", &minhaArvAVL4, &rotacoesAVL4);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (AVL1-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoAVL("arqAVL2_20000.txt", &minhaArvAVL5, &rotacoesAVL5);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (AVL2-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoAVL("arqAVL3_20000.txt", &minhaArvAVL6, &rotacoesAVL6);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (AVL3-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoRN("arqRN1_5000.txt", &minhaArvRN1, &rotacoesRN1);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (RN1-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoRN("arqRN2_5000.txt", &minhaArvRN2, &rotacoesRN2);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (RN2-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoRN("arqRN3_5000.txt", &minhaArvRN3, &rotacoesRN3);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (RN3-5000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoRN("arqRN1_20000.txt", &minhaArvRN4, &rotacoesRN4);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (RN1-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoRN("arqRN2_20000.txt", &minhaArvRN5, &rotacoesRN5);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (RN2-20000): %.6f segundos\n", tempo_insercao);

    gettimeofday(&tempo_inicio, NULL);
    le_arquivoRN("arqRN3_20000.txt", &minhaArvRN6, &rotacoesRN6);
    gettimeofday(&tempo_fim, NULL);
    tempo_insercao = (tempo_fim.tv_sec - tempo_inicio.tv_sec) + (tempo_fim.tv_usec - tempo_inicio.tv_usec) / 1000000.0;
    printf("Tempo de insercao (RN3-20000): %.6f segundos\n", tempo_insercao);

    //Rotações das árvores balanceadas
    printf("Rotacoes (RN1-5000): %d\n", rotacoesRN1);
    printf("Rotacoes (RN2-5000): %d\n", rotacoesRN2);
    printf("Rotacoes (RN3-5000): %d\n", rotacoesRN3);
    printf("Rotacoes (RN4-20000): %d\n", rotacoesRN4);
    printf("Rotacoes (RN5-20000): %d\n", rotacoesRN5);
    printf("Rotacoes (RN6-20000): %d\n", rotacoesRN6);
    printf("Rotacoes (AVL1-5000): %d\n", rotacoesAVL1);
    printf("Rotacoes (AVL2-5000): %d\n", rotacoesAVL2);
    printf("Rotacoes (AVL3-5000): %d\n", rotacoesAVL3);
    printf("Rotacoes (AVL1-20000): %d\n", rotacoesAVL4);
    printf("Rotacoes (AVL2-20000): %d\n", rotacoesAVL5);
    printf("Rotacoes (AVL3-20000): %d\n", rotacoesAVL6);


    //Altura das árvores
    printf("Altura (ABB1-5000): %d\n", alturaArvore(minhaArvBB1));
    printf("Altura (ABB2-5000): %d\n", alturaArvore(minhaArvBB2));
    printf("Altura (ABB3-5000): %d\n", alturaArvore(minhaArvBB3));
    printf("Altura (ABB1-20000): %d\n", alturaArvore(minhaArvBB4));
    printf("Altura (ABB2-20000): %d\n", alturaArvore(minhaArvBB5));
    printf("Altura (ABB3-20000): %d\n", alturaArvore(minhaArvBB6));
    printf("Altura (AVL1-5000): %d\n", altura_NO(minhaArvAVL1));
    printf("Altura (AVL2-5000): %d\n", altura_NO(minhaArvAVL2));
    printf("Altura (AVL3-5000): %d\n", altura_NO(minhaArvAVL3));
    printf("Altura (AVL1-20000): %d\n", altura_NO(minhaArvAVL4));
    printf("Altura (AVL2-20000): %d\n", altura_NO(minhaArvAVL5));
    printf("Altura (AVL3-20000): %d\n", altura_NO(minhaArvAVL6));
    printf("Altura (RN1-5000): %d\n", alturaRN(minhaArvRN1));
    printf("Altura (RN2-5000): %d\n", alturaRN(minhaArvRN2));
    printf("Altura (RN3-5000): %d\n", alturaRN(minhaArvRN3));
    printf("Altura (RN1-20000): %d\n", alturaRN(minhaArvRN4));
    printf("Altura (RN2-20000): %d\n", alturaRN(minhaArvRN5));
    printf("Altura (RN3-20000): %d\n", alturaRN(minhaArvRN6));

    //Buscando valores nas estruturas e contando as comparações em cada busca
    int *valoresABB1, *valoresABB2, *valoresABB3, *valoresABB4, *valoresABB5, *valoresABB6;

    int tam1 = 5000;
    int tam2 = 20000;

    seleciona_20porcento("arqABB1_5000.txt", &valoresABB1, tam1);
    seleciona_20porcento("arqABB2_5000.txt", &valoresABB2, tam1);
    seleciona_20porcento("arqABB3_5000.txt", &valoresABB3, tam1);
    seleciona_20porcento("arqABB1_20000.txt", &valoresABB4, tam2);
    seleciona_20porcento("arqABB2_20000.txt", &valoresABB5, tam2);
    seleciona_20porcento("arqABB3_20000.txt", &valoresABB6, tam2);
    
    double tempoTotalABB1 = 0.0, tempoTotalABB2 = 0.0, tempoTotalABB3 = 0.0, tempoTotalABB4 =0.0;
    double tempoTotalABB5 = 0.0, tempoTotalABB6 = 0.0;
    int comparacoesABB1 = 0, comparacoesABB2 = 0, comparacoesABB3 = 0;
    int comparacoesABB4 = 0, comparacoesABB5 = 0, comparacoesABB6 = 0;

    busca_abb(minhaArvBB1, valoresABB1, tam1, &comparacoesABB1, &tempoTotalABB1);
    busca_abb(minhaArvBB2, valoresABB2, tam1, &comparacoesABB2, &tempoTotalABB2);
    busca_abb(minhaArvBB3, valoresABB3, tam1, &comparacoesABB3, &tempoTotalABB3);
    busca_abb(minhaArvBB4, valoresABB4, tam2, &comparacoesABB4, &tempoTotalABB4);
    busca_abb(minhaArvBB5, valoresABB5, tam2, &comparacoesABB5, &tempoTotalABB5);
    busca_abb(minhaArvBB6, valoresABB6, tam2, &comparacoesABB6, &tempoTotalABB6);
    
    printf("ABB1 - Comparacoes Totais: %d\n", comparacoesABB1);
    printf("ABB1 - Tempo Total: %.6f segundos\n", tempoTotalABB1);
    printf("ABB2 - Comparacoes Totais: %d\n", comparacoesABB2);
    printf("ABB2 - Tempo Total: %.6f segundos\n", tempoTotalABB2);
    printf("ABB3 - Comparacoes Totais: %d\n", comparacoesABB3);
    printf("ABB3 - Tempo Total: %.6f segundos\n", tempoTotalABB3);
    printf("ABB4 - Comparacoes Totais: %d\n", comparacoesABB4);
    printf("ABB4 - Tempo Total: %.6f segundos\n", tempoTotalABB4);
    printf("ABB5 - Comparacoes Totais: %d\n", comparacoesABB5);
    printf("ABB5 - Tempo Total: %.6f segundos\n", tempoTotalABB5);
    printf("ABB6 - Comparacoes Totais: %d\n", comparacoesABB6);
    printf("ABB6 - Tempo Total: %.6f segundos\n", tempoTotalABB6);
  

    int *valoresAVL1, *valoresAVL2, *valoresAVL3, *valoresAVL4, *valoresAVL5, *valoresAVL6;

    seleciona_20porcento("arqAVL1_5000.txt", &valoresAVL1, tam1);
    seleciona_20porcento("arqAVL2_5000.txt", &valoresAVL2, tam1);
    seleciona_20porcento("arqAVL3_5000.txt", &valoresAVL3, tam1);
    seleciona_20porcento("arqAVL1_20000.txt", &valoresAVL4, tam2);
    seleciona_20porcento("arqAVL2_20000.txt", &valoresAVL5, tam2);
    seleciona_20porcento("arqAVL3_20000.txt", &valoresAVL6, tam2);

    double tempoTotalAVL1 = 0.0, tempoTotalAVL2 = 0.0, tempoTotalAVL3 = 0.0, tempoTotalAVL4 =0.0;
    double tempoTotalAVL5 = 0.0, tempoTotalAVL6 = 0.0;
    int comparacoesAVL1, comparacoesAVL2, comparacoesAVL3, comparacoesAVL4, comparacoesAVL5, comparacoesAVL6;
    comparacoesAVL1 = 0, comparacoesAVL2 = 0, comparacoesAVL3 = 0;
    comparacoesAVL4 = 0, comparacoesAVL5 = 0, comparacoesAVL6 = 0;

    busca_avl(minhaArvAVL1, valoresAVL1, tam1, &comparacoesAVL1, &tempoTotalAVL1);
    busca_avl(minhaArvAVL2, valoresAVL2, tam1, &comparacoesAVL2, &tempoTotalAVL2);
    busca_avl(minhaArvAVL3, valoresAVL3, tam1, &comparacoesAVL3, &tempoTotalAVL3);
    busca_avl(minhaArvAVL4, valoresAVL4, tam2, &comparacoesAVL4, &tempoTotalAVL4);
    busca_avl(minhaArvAVL5, valoresAVL5, tam2, &comparacoesAVL5, &tempoTotalAVL5);
    busca_avl(minhaArvAVL6, valoresAVL6, tam2, &comparacoesAVL6, &tempoTotalAVL6);

    printf("AVL1 - Comparacoes Totais: %d\n", comparacoesAVL1);
    printf("AVL1 - Tempo Total: %.6f segundos\n", tempoTotalAVL1);
    printf("AVL2 - Comparacoes Totais: %d\n", comparacoesAVL2);
    printf("AVL2 - Tempo Total: %.6f segundos\n", tempoTotalAVL2);
    printf("AVL3 - Comparacoes Totais: %d\n", comparacoesAVL3);
    printf("AVL3 - Tempo Total: %.6f segundos\n", tempoTotalAVL3);
    printf("AVL4 - Comparacoes Totais: %d\n", comparacoesAVL4);
    printf("AVL4 - Tempo Total: %.6f segundos\n", tempoTotalAVL4);
    printf("AVL5 - Comparacoes Totais: %d\n", comparacoesAVL5);
    printf("AVL5 - Tempo Total: %.6f segundos\n", tempoTotalAVL5);
    printf("AVL6 - Comparacoes Totais: %d\n", comparacoesAVL6);
    printf("AVL6 - Tempo Total: %.6f segundos\n", tempoTotalAVL6);
  
    int *valoresRN1, *valoresRN2, *valoresRN3, *valoresRN4, *valoresRN5, *valoresRN6;

    seleciona_20porcento("arqRN1_5000.txt", &valoresRN1, tam1);
    seleciona_20porcento("arqRN2_5000.txt", &valoresRN2, tam1);
    seleciona_20porcento("arqRN3_5000.txt", &valoresRN3, tam1);
    seleciona_20porcento("arqRN1_20000.txt", &valoresRN4, tam2);
    seleciona_20porcento("arqRN2_20000.txt", &valoresRN5, tam2);
    seleciona_20porcento("arqRN3_20000.txt", &valoresRN6, tam2);

    double tempoTotalRN1 = 0.0, tempoTotalRN2 = 0.0, tempoTotalRN3 = 0.0, tempoTotalRN4 =0.0;
    double tempoTotalRN5 = 0.0, tempoTotalRN6 = 0.0;
     
    int comparacoesRN1, comparacoesRN2, comparacoesRN3, comparacoesRN4, comparacoesRN5, comparacoesRN6;
    comparacoesRN1 = 0, comparacoesRN2 = 0, comparacoesRN3 = 0;
    comparacoesRN4 = 0, comparacoesRN5 = 0, comparacoesRN6 = 0;

    busca_rubro_negra(minhaArvRN1, valoresRN1, tam1, &comparacoesRN1, &tempoTotalRN1);
    busca_rubro_negra(minhaArvRN2, valoresRN2, tam1, &comparacoesRN2, &tempoTotalRN2);
    busca_rubro_negra(minhaArvRN3, valoresRN3, tam1, &comparacoesRN3, &tempoTotalRN3);
    busca_rubro_negra(minhaArvRN4, valoresRN4, tam2, &comparacoesRN4, &tempoTotalRN4);
    busca_rubro_negra(minhaArvRN5, valoresRN5, tam2, &comparacoesRN5, &tempoTotalRN5);
    busca_rubro_negra(minhaArvRN6, valoresRN6, tam2, &comparacoesRN6, &tempoTotalRN6);

    printf("RN1 - Comparacoes Totais: %d\n", comparacoesRN1);
    printf("RN1 - Tempo Total: %.6f segundos\n", tempoTotalRN1);
    printf("RN2 - Comparacoes Totais: %d\n", comparacoesRN2);
    printf("RN2 - Tempo Total: %.6f segundos\n", tempoTotalRN2);
    printf("RN3 - Comparacoes Totais: %d\n", comparacoesRN3);
    printf("RN3 - Tempo Total: %.6f segundos\n", tempoTotalRN3);
    printf("RN4 - Comparacoes Totais: %d\n", comparacoesRN4);
    printf("RN4 - Tempo Total: %.6f segundos\n", tempoTotalRN4);
    printf("RN5 - Comparacoes Totais: %d\n", comparacoesRN5);
    printf("RN5 - Tempo Total: %.6f segundos\n", tempoTotalRN5);
    printf("RN6 - Comparacoes Totais: %d\n", comparacoesRN6);
    printf("RN6 - Tempo Total: %.6f segundos\n", tempoTotalRN6);
  
    free(minhaArvAVL1);
    free(minhaArvAVL2);
    free(minhaArvAVL3);
    free(minhaArvAVL4);
    free(minhaArvAVL5);
    free(minhaArvAVL6);

    free(minhaArvBB1);
    free(minhaArvBB2);
    free(minhaArvBB3);
    free(minhaArvBB4);
    free(minhaArvBB5);
    free(minhaArvBB6);

    free(minhaArvRN1);
    free(minhaArvRN2);
    free(minhaArvRN3);
    free(minhaArvRN4);
    free(minhaArvRN5);
    free(minhaArvRN6);

    free(valoresABB1);
    free(valoresABB2);
    free(valoresABB3);
    free(valoresABB4);
    free(valoresABB5);
    free(valoresABB6);

    free(valoresAVL1);
    free(valoresAVL2);
    free(valoresAVL3);
    free(valoresAVL4);
    free(valoresAVL5);
    free(valoresAVL6);

    free(valoresRN1);
    free(valoresRN2);
    free(valoresRN3);
    free(valoresRN4);
    free(valoresRN5);
    free(valoresRN6);

    printf("===========================================================================================\n");
    return EXIT_SUCCESS;
}

//Função que gera os dados pseudo-aleatórios e os armazena em um arquivo .txt;
void gerar_dados(int vlr, const char *nome_arq) {
    int *valores = (int *) malloc(vlr * sizeof(int));
    if (valores == NULL) {
        fprintf(stderr, "[ERRO] Falha ao alocar a memória.\n");
        exit(1);
    }

    int i, j, valor, flag;
    srand(time(NULL));

    FILE *arq = fopen(nome_arq, "w");
    if (arq == NULL) {
        fprintf(stderr, "[ERRO] Falha ao abrir o arquivo.\n");
        free(valores);
        exit(1);
    }

    for (i = 0; i < vlr; i++) {
        do {
            flag = 1;
            valor = 1 + rand() % 100000;

            // Verifica se o número já existe no vetor
            for (j = 0; j < i; j++) {
                if (valor == valores[j]) {
                    flag = 0;
                    break;
                }
            }
        } while (flag == 0);

        valores[i] = valor;
        fprintf(arq, "%d\n", valor);
    }

    fclose(arq);
    free(valores);
}


void seleciona_20porcento(const char *nome_arq, int **num, int tam) {
    int total_valores = tam;
    int num_selecionados = total_valores * 0.2;
    int *todos_valores = (int *)malloc(total_valores * sizeof(int));
    int *valores_selecionados = (int *)malloc(num_selecionados * sizeof(int));

    FILE *file = fopen(nome_arq, "r");
    if (file == NULL) {
        printf("[ERRO] não foi possível abrir o arquivo!");
        exit(1);
    }

    for (int i = 0; i < total_valores; i++) {
        fscanf(file, "%d", &todos_valores[i]);
    }
    fclose(file);

    srand(time(NULL));
    for (int i = 0; i < num_selecionados; i++) {
        int indice = rand() % total_valores;
        valores_selecionados[i] = todos_valores[indice];
    }

    *num = valores_selecionados;
    free(todos_valores);
}
