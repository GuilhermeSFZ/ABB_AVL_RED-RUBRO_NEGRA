# ABB_AVL_RUBRO-NEGRA_TREES
O trabalho consiste em criar um algoritmo que gere arquivos com números inteiros aleatórios, implementar árvores binárias (Clássica (Árvore Binária de Busca - BST), AVL e Rubro-Negra/Red-Black), e realizar operações de inserção e busca, contabilizando rotações, comparações e tempo de execução.
Descrição:
Etapa 1:
Elabore um algoritmo que gere um arquivo contendo um conjunto de valores inteiros, definidos aleatoriamente, não repetidos, no intervalo entre 1 e 100.000, sendo um valor por linha. O Algoritmo receberá como parâmetros de chamada o número de valores a serem gerados e nome do arquivo de saída.

Exemplo: > ./xpto 500  out.txt

onde xpto é o nome do algoritmo executável, 500 é o número de valores a serem gerados e out.txt o nome do arquivo de saída com os dado gerados

Etapa 2:
Implemente as funções necessárias para a construção e manipulação (busca e inserção) de Árvore Binária Busca (Clássica), Árvore AVL e Árvore Rubro-Negra. Implemente também as funções para análise da árvore, especialmente a função que identifica a altura da árvore, que contabilize o tempo e número de comparações no processo de busca de um valor e contabilize o número de rotações executadas em um procedimento de inserção (no caso de árvores balanceadas). As implementações deverão ser independentes (um programa/algoritmo para cada tipo de árvore).

Etapa 3:
Gere 3 arquivos de entradas com 5.000 números e 3 arquivos com 20.000 números.
Para cada uma dos arquivos, carregue em cada uma dos algoritmos das árvores(Árvore Binária Busca (Clássica), contabilize o total de rotações executadas e a altura das árvores resultantes após a inserção dos valores informados pelo arquivo de entrada. O processo de avaliação deverá executar o mesmo arquivo de entrada para cada tipo de árvore binária (Binária Clássica, AVL e Rubro-Negra) e então comparar as diferenças em relação à altura e o número de rotações executadas em cada tipo de árvore.

Etapa 4:
Para cada arquivos gerado na etapa 3, e carregado nas árvores, crie uma função que selecione aleatoriamente 20% dos valores gerados, faça a busca por cada valor na árvore e calcule o tempo e número de comparações realizadas.
