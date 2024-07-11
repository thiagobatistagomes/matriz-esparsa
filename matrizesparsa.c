#include <stdio.h>
#include <stdlib.h>

#include "matrizesparsa.h"



// Define a estrutura de cada célula na matriz esparsa
struct celula
{
  int linha, coluna;  // Posição (linha, coluna) da célula na matriz
  float valor;        // Valor armazenado na célula
  struct celula *direita, *abaixo;  // Ponteiros para a próxima célula à direita e abaixo na matriz
};

// Define a estrutura para a matriz esparsa
struct tipomatrizesparsa
{
  int linhas, colunas;  // Número de linhas e colunas na matriz
  TipoCelula *inicio, *fimLinha, *fimColuna;  // Ponteiros para as células iniciais, finais de linha e coluna
};


MatrizEsparsa *CriarMatrizEsparsa(int linhas, int colunas)
{
  MatrizEsparsa *matriz = (MatrizEsparsa *)malloc(sizeof(MatrizEsparsa)); // aloca memoria do tipo matriz esparsa

  if(!matriz || linhas <= 0 || colunas <= 0) // se a alocacao falhar, ou os parametros forem incorretos retorna 0
  {
    return 0;
  }

  // inicia as variaveis da struct matriz esparsa
  matriz->inicio = NULL;
  matriz->fimLinha = NULL;
  matriz->fimColuna = NULL;
  matriz->linhas = linhas;
  matriz->colunas = colunas;

  IniciaCabecas(matriz);

  return matriz;
}

int IniciaCabecas(MatrizEsparsa *matriz)
{
  int i = 0;

  TipoCelula *cabeca;
  cabeca = (TipoCelula *)malloc(sizeof(TipoCelula));

  if(!cabeca) // se a alocacao falhar retorna 0
  {
    return 0;
  }

  // inicializa a celula principal com -1
  cabeca->linha = -1;
  cabeca->coluna = -1;


  matriz->inicio = cabeca;
  matriz->fimLinha = cabeca;
  matriz->fimColuna = cabeca;

  for(i = 1; i <= matriz->colunas; i++)
  {
    IniciarColuna(matriz);
  }

  for(i = 1; i <= matriz->linhas; i++)
  {
    IniciarLinha(matriz);
  }
}


int IniciarColuna(MatrizEsparsa *matriz)
{
  TipoCelula *cabeca;
  cabeca = (TipoCelula *)malloc(sizeof(TipoCelula));

  if(!cabeca)
  {
    return 0;
  }

  cabeca->coluna = -1;
  cabeca->linha = 0;

  matriz->fimColuna->direita = cabeca;
  matriz->fimColuna = cabeca;

  cabeca->direita = matriz->inicio;
  cabeca->abaixo = cabeca;

  return 1;
}

int IniciarLinha(MatrizEsparsa *matriz)
{
  TipoCelula *cabeca;
  cabeca = (TipoCelula *)malloc(sizeof(TipoCelula));

  if(!cabeca)
  {
    return 0;
  }

  cabeca->linha = -1;
  cabeca->coluna = 0;

  matriz->fimLinha->abaixo = cabeca;
  matriz->fimLinha = cabeca;

  cabeca->abaixo = matriz->inicio;
  cabeca->direita = cabeca;

  return 1;
}

int InserirElemento(MatrizEsparsa *matriz, int linha, int coluna, float valor)
{
  int i;

  if(!matriz || matriz->linhas <= 0 || matriz->colunas <= 0 || !valor) 
  { 
      return 0;
  }
  if(linha>matriz->linhas || coluna>matriz->colunas || !valor || linha < 1 || coluna < 1)
  {
      return 0;
  }

  TipoCelula *tempCelula; //celula temporaria
  TipoCelula *tempCelulaColuna; //celula temporaria para coluna
  TipoCelula *tempCelulaLinha; //celula temporaria para linha

  tempCelula = (TipoCelula*)malloc(sizeof(TipoCelula));

  if(!tempCelula)
  { 
    return 0;
  }

  tempCelula->linha = linha;
  tempCelula->coluna = coluna;
  tempCelula->valor = valor;

  tempCelulaLinha = matriz->inicio->abaixo; //linha aponta para a primeira cabeca  de linha
  tempCelulaColuna = matriz->inicio->direita; //linha aponta para a primeira cabeca  de coluna

  //Percorre ate a linha do elemento, percorre nas cabecas ate a informada
  for(i = 0; i < linha-1; i++) //-1 pq ja ta na primeira
  { 
      tempCelulaLinha = tempCelulaLinha->abaixo; //percorre para baixo(linhas) ate achar a correta
  }

  i = 0;

  while(i < coluna && tempCelulaLinha->direita->linha != -1)
  {
      if(tempCelulaLinha->direita->coluna > tempCelula->coluna) //se a celula inserida esta a esquerda
      { 
          tempCelula->direita = tempCelulaLinha->direita;
          tempCelulaLinha->direita = tempCelula;
      }
      else
      {
          tempCelulaLinha = tempCelulaLinha->direita; //anda pelas celulas a direita
      }
      i++;
  }
  if(tempCelulaLinha->direita->linha == -1) //a celula esta mais a direita
  { 
      tempCelula->direita = tempCelulaLinha->direita; //aponta para a cabeca
      tempCelulaLinha->direita = tempCelula; //ultima celula ou cabeca, senao tiver celulas, aponta para a celula
  }
  //linha encontrada e apontada

  //encontrar a coluna
  //Percorre ate a coluna do elemento, percorre nas cabecas ate a informada
  for(i = 0; i < coluna-1; i++) //-1 pq ja ta na primeira
  { 
      tempCelulaColuna = tempCelulaColuna->direita; //percorre a direita (colunas) ate achar a correta
  }

  i = 0;

  while(i < linha && tempCelulaColuna->abaixo->coluna != -1) //anda pelas celulas ate achar a posicao
  { 
      if (tempCelulaColuna->abaixo->linha > tempCelula->linha)
      {
          tempCelula->abaixo = tempCelulaColuna->abaixo;
          tempCelulaColuna->abaixo = tempCelula;
      }
      else
      {
          tempCelulaColuna = tempCelulaColuna->abaixo; //anda pelas celulas abaixo
      }
      i++;
  }
  if(tempCelulaColuna->abaixo->coluna == -1)
  {
      tempCelula->abaixo = tempCelulaColuna->abaixo; //aponta para a cabeca
      tempCelulaColuna->abaixo = tempCelula; //ultima celula ou cabeca, senao tiver celulas, aponta para a celula
  }
  return 1;
}


int ImprimirMatriz(MatrizEsparsa *matriz)
{
  int i, j;
  TipoCelula *tempCelula;

  if(!matriz || !matriz->linhas || !matriz->colunas)
  {
    return 0;
  }

  tempCelula = matriz->inicio->abaixo;

  printf("\n");

  for(i = 1; i <= matriz->linhas; i++)
  {
    for(j = 1; j <= matriz->colunas; j++)
    {
      if(tempCelula->direita->linha == i && tempCelula->direita->coluna == j)
      {
        tempCelula = tempCelula->direita;
        printf("  \t%0.2f   ", tempCelula->valor);
      }
      else
      {
        printf("  \t%0.2f   ", 0.0F);
      }
    }
    printf("\n");
    tempCelula = tempCelula->direita->abaixo;
  }

  return 1;
}

int LiberarMatriz(MatrizEsparsa *matriz)
{
  int i = 1, j = 1;
  TipoCelula *tempCelula, *aux;

  if(!matriz || !matriz->linhas || !matriz->colunas)
  {
    return 0;
  }

  tempCelula = matriz->inicio->abaixo;
  tempCelula = tempCelula->direita;

  for(i = 1; i < matriz->linhas; i++)
  {
    for(j = 1; j < matriz->colunas; j++)
    {
      if(tempCelula->linha == i &&  tempCelula->coluna == j)
      {
        aux = tempCelula;
        tempCelula = tempCelula->direita;
        free(aux);
      }
    }
    tempCelula = tempCelula->abaixo->direita;
  }

  // apaga cabecas

  tempCelula = matriz->inicio->direita;
  for(i = 0; i < matriz->colunas; i ++) // cabecas coluna
  {
    aux = tempCelula;
    tempCelula = tempCelula->direita;
    free(aux);
  }

  tempCelula = matriz->inicio->abaixo;
  for(i = 0; i < matriz->linhas; i ++) // cabecas linha
  {
    aux = tempCelula;
    tempCelula = tempCelula->abaixo;
    free(aux);
  }

  tempCelula = matriz->inicio;
  free(tempCelula);

  matriz->fimColuna = matriz->fimLinha = matriz->inicio = NULL;
  matriz->linhas = matriz->colunas = 0;
  matriz = NULL;


  return 1;
}


MatrizEsparsa *SomarMatrizes(MatrizEsparsa *matrizA, MatrizEsparsa *matrizB)
{
  int i, j;
  float soma;
  MatrizEsparsa *matrizC;
  TipoCelula *tempCelulaA, *tempCelulaB;

  if(matrizA->linhas != matrizB->linhas || matrizA->colunas != matrizB->colunas) //as matrizes devem ser de mesma ordem para somar
  { 
    return NULL;
  }

  if(!matrizA || !matrizB || !matrizA->linhas || !matrizA->colunas)
  {
    return NULL;
  }

  matrizC = CriarMatrizEsparsa(matrizA->linhas, matrizB->colunas);

  tempCelulaA = matrizA->inicio->abaixo;
  tempCelulaB = matrizB->inicio->abaixo;

  for(i = 1; i <= matrizA->linhas; i++)
  {
    for(j = 1; j <= matrizA->colunas; j++)
    {
      if(j == tempCelulaA->direita->coluna && j == tempCelulaB->direita->coluna)
      {
        soma = tempCelulaA->direita->valor + tempCelulaB->direita->valor;
        if (soma)
        {
          InserirElemento(matrizC, i, j, soma);
        }
        tempCelulaA = tempCelulaA->direita;
        tempCelulaB = tempCelulaB->direita;
      }
      else if(j == tempCelulaA->direita->coluna)
      {
        InserirElemento(matrizC, i, j, tempCelulaA->direita->valor);
        tempCelulaA = tempCelulaA->direita;
      }
      else if(j == tempCelulaB->direita->coluna)
      {
        InserirElemento(matrizC, i, j,tempCelulaB->direita->valor);
        tempCelulaB = tempCelulaB->direita;
      }
    }
    tempCelulaA = tempCelulaA->direita->abaixo;
    tempCelulaB = tempCelulaB->direita->abaixo;
  }

    return matrizC;
}


MatrizEsparsa *MultiplicarMatriz(MatrizEsparsa *matrizA, MatrizEsparsa *matrizB)
{
  int i = 0, j = 0, k = 0;
  float total;
  MatrizEsparsa *matrizC;

  if (matrizA->colunas != matrizB->linhas) //so pode multiplicar se o numero de colunas de A eh igual ao numero de linhas de B
  { 
    printf("\nNao foi possivel multiplicar as matrizes\nnumero de colunas de A eh diferente do numero de linhas de B\n");
    return NULL;
  }

  if(!matrizA || !matrizB || !matrizA->linhas || !matrizA->colunas || !matrizB->colunas)
  {
    return NULL;
  }

    matrizC = CriarMatrizEsparsa(matrizA->linhas, matrizB->colunas); //C é formada pelo numero de linhas de A e de colunas de B

  for(i = 1; i <= matrizA->linhas; i++)
  {
    for(j = 1; j <= matrizB->colunas; j++)
    {
      total = 0;
      for(k = 1; k <= matrizA->colunas; k++)
      {
        total += BuscarIndice(matrizA,i,k) * BuscarIndice(matrizB,k,j);
      }
        if(total)
        {
          InserirElemento(matrizC,i,j,total);
        }
      }
    }
    return matrizC;
}

float BuscarIndice(MatrizEsparsa *matriz, int linha, int coluna)
{
  TipoCelula *tempCelula;
  int i = 0;

  tempCelula = matriz->inicio->direita;

  for(i = 0; i < coluna-1; i++) //chega na coluna desejada
  { 
    tempCelula = tempCelula->direita;
  }

  do{
      tempCelula = tempCelula->abaixo;
      if(tempCelula->linha == linha)
      {
        return tempCelula->valor;
      }
    }while(tempCelula->coluna != -1);

    return 0; //elemento nao encontrado
}