#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H



typedef struct tipomatrizesparsa MatrizEsparsa;
typedef struct celula TipoCelula;

// Declaração das funções que operam na matriz esparsa

// Cria uma nova matriz esparsa com o número especificado de linhas e colunas
MatrizEsparsa *CriarMatrizEsparsa(int linhas, int colunas);

// Inicializa as cabeças da matriz esparsa
int IniciaCabecas(MatrizEsparsa *matriz);

// Inicializa uma nova coluna na matriz esparsa
int IniciarColuna(MatrizEsparsa *matriz);

// Inicializa uma nova linha na matriz esparsa
int IniciarLinha(MatrizEsparsa *matriz);

// Insere um elemento na matriz esparsa na posição (linha, coluna) com o valor especificado
int InserirElemento(MatrizEsparsa *matriz, int linha, int coluna, float valor);

// Imprime a representação da matriz esparsa
int ImprimirMatriz(MatrizEsparsa *matriz);

// Libera a memória alocada para a matriz esparsa
int LiberarMatriz(MatrizEsparsa *matriz);

// Busca e retorna o valor na posição (linha, coluna) da matriz esparsa
float BuscarIndice(MatrizEsparsa *matriz, int linha, int coluna);

// Soma duas matrizes esparsas e retorna uma nova matriz com o resultado
MatrizEsparsa *SomarMatrizes(MatrizEsparsa *matrizA, MatrizEsparsa *matrizB);

// Multiplica duas matrizes esparsas e retorna uma nova matriz com o resultado
MatrizEsparsa *MultiplicarMatriz(MatrizEsparsa *matrizA, MatrizEsparsa *matrizB);

#endif //MATRIZ_ESPARSA_H