#include <stdio.h>
#include <stdlib.h>

#include "matrizesparsa.h"

int main(void)
{
  int opcao, ok, n, lin, col;
  float valor;
  MatrizEsparsa *matrizA = NULL;
  MatrizEsparsa *matrizB = NULL;
  MatrizEsparsa *matrizC = NULL;

  do
  {
    printf("Menu de Opcoes:\n");
    printf("0 - Sair.\n");
    printf("1 - Criar Matriz Esparsa.\n");
    printf("2 - Liberar Matriz Esparsa.\n");
    printf("3 - Inserir Valor.\n");
    printf("4 - Buscar Valor.\n");
    printf("5 - Somar Matrizes.\n");
    printf("6 - Multiplicar Matrizes.\n");
    printf("7 - Imprimir.\n");
    scanf("%d", &opcao);

    switch(opcao)
    {
      case 0:
        printf("Encerrando...\n");
        if(matrizA || matrizB || matrizC) // se o usuario se esquecer de liberar alguma das matrizes
        {
          LiberarMatriz(matrizA);
          LiberarMatriz(matrizB);
          LiberarMatriz(matrizC);
          matrizA = NULL;
          matrizB = NULL;
          matrizC = NULL; // libera todas as matrizes e finaliza o programa
        }
        break;

      case 1:
        printf("Qual matriz deseja criar?\n");
        printf("Selecione 1 caso queria criar a Matriz A.\nSelecione 2 caso queira criar a Matriz B.\n");
        scanf("%d", &n);
        switch(n)
        {
          case 1: // criar
            if(matrizA == NULL) // se a matriz ainda nao foi criada permite a criacao dela
            {
              printf("Digite o tamanho da matriz em Linhas e Colunas respectivamente: \n");
              scanf("%d %d", &lin, &col);
              matrizA = CriarMatrizEsparsa(lin, col);
              if(matrizA)
              {
                printf("Matriz criada com sucesso!\n");
              }
              else // senao gera um aviso
              {
                printf("Falha na criacao da matriz!\n");
              }
            }
            else
            {
              printf("A matriz já existe!\n");
            }
            break;

          case 2:
            if(matrizB == NULL)
            {
              printf("Digite o tamanho da matriz em Linhas e Colunas respectivamente: \n");
              scanf("%d %d", &lin, &col);
              matrizB = CriarMatrizEsparsa(lin, col);
              if(matrizB)
              {
                printf("Matriz criada com sucesso!\n");
              }
              else
              {
                printf("Falha na criacao da matriz!\n");
              }
            }
            else
            {
              printf("A matriz já existe!\n");
            }
            break;

          default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

      case 2: // liberar
        printf("Qual matriz deseja liberar?\n");
        printf("Selecione 1 caso queira liberar a Matriz A.\nSelecione 2 caso queira liberar a matriz B.\n");
        scanf("%d", &n);
        switch(n)
        {
          case 1:
            if (matrizA != NULL) // se a matriz ja foi criada permite a liberacao dela
            {
                ok = LiberarMatriz(matrizA);
                if (ok)
                {
                    printf("Matriz A liberada com sucesso!\n");
                  matrizA = NULL; // libera a matriz e define ela como nula
                } else
                {
                    printf("Falha na liberacao da matriz A!\n");
                }
            }
            else // senao avisa o usuario
            {
                printf(" A matriz A nao existe!\n");
            }
            break;

          case 2:
            if (matrizB != NULL)
            {
                ok = LiberarMatriz(matrizB);
                if (ok)
                {
                    printf("Matriz B liberada com sucesso!\n");
                  matrizB = NULL;
                } else
                {
                    printf("Falha na liberacao da matriz B!\n");
                }
            }
            else
            {
                printf("A matriz B nao existe!\n");
            }
            break;

          default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

      case 3: // inserir
        printf("Em qual matriz o valor sera inserido?\n");
        printf("Selecione 1 caso queira inserir na Matriz A.\nSelecione 2 caso queira inserir na matriz B.\n");
        scanf("%d", &n);
        switch(n)
        {
          case 1:
            if(matrizA != NULL) // se a matriz A ja foi criada permite inserir elementos nela
            {
              printf("Digite a linha e a coluna onde pretende inserir o valor: \n");
              scanf("%d %d", &lin, &col);
              printf("Digite o valor a ser inserido: \n");
              scanf("%f", &valor);
              ok = InserirElemento(matrizA, lin, col, valor);
              if(ok)
              {
                printf("Valor inserido com sucesso!\n");
              }
              else
              {
                printf("Falha na insercao do valor! Verifique os parametros e tente novamente!\n");
              }
            }
            else
            {
              printf("A matriz A nao existe!\n");
            }
            break;

          case 2:
            if(matrizB != NULL)
            {
              printf("Digite a linha e a coluna onde pretende inserir o valor: \n");
              scanf("%d %d", &lin, &col);
              printf("Digite o valor a ser inserido: \n");
              scanf("%f", &valor);
              ok = InserirElemento(matrizB, lin, col, valor);
              if(ok)
              {
                printf("Valor inserido com sucesso!\n");
              }
              else
              {
                printf("Falha na insercao do valor! Verifique os parametros e tente novamente!\n");
              }
            }
            else
            {
              printf("A matriz B nao existe!\n");
            }
            break;

          default:
            printf("Opcao invalida!\n");
            break;
        }
        break;

      case 4: // buscar
        printf("Em qual matriz o valor sera buscado?\n");
        printf("Selecione 1 caso queira buscar na Matriz A.\nSelecione 2 caso queira buscar na matriz B.\n");
        scanf("%d", &n);
        switch(n)  
        {
          case 1:
            if(matrizA != NULL)
            {
              printf("Digite o valor da linha e coluna em que o valor sera buscado:\n");
              scanf("%d %d", &lin, &col);
              printf("Valor de (%d, %d):\n", lin, col);
              printf("Valor: %.2f\n", BuscarIndice(matrizA, lin, col));
            }
            else
            {
              printf("A matriz A nao existe!\n");
            }
            break;

          case 2:
            if(matrizB != NULL)
            {
              printf("Digite o valor da linha e coluna em que o valor sera buscado:\n");
              scanf("%d %d", &lin, &col);
              printf("Valor de (%d, %d):\n", lin, col);
              printf("Valor: %.2f\n", BuscarIndice(matrizB, lin, col));
            }
            else
            {
              printf("A matriz B nao existe!\n");
            }
            break;

          default:
            printf("Opcao Invalida!\n");
            break;
        }
        break;

      case 5: // somar matrizes
        if(matrizA && matrizB) // ambas as matrizes existem e e possivel realizar a soma
        {
          matrizC = SomarMatrizes(matrizA, matrizB); // soma as matrizes A e B e guarda o resultado em matrizC
          if(matrizC != NULL) // se a matriz C foi criada corretamente
          {
            printf("Matriz C:\n");
            ImprimirMatriz(matrizC); // imprime a matriz C
            printf("\n");
          }
          else
          {
            printf("Falha na soma das matrizes!\n");
          }
        }
        else if(!matrizA)
        {
          printf("A matriz A nao existe! Nao e possivel realizar a soma!\n");
        }
        else if(!matrizB)
        {
          printf("A matriz B nao existe! Nao e possivel realizar a soma!\n");
        }
        else
        {
          printf("Ambas as matrizes A e B nao existem! Nao e possivel realizar a soma!\n");
        }
        break;

      case 6: // multiplicar
        if(matrizA && matrizB) // ambas as matrizes existem e e possivel realizar a multiplicacao
        {
          matrizC = MultiplicarMatriz(matrizA, matrizB); // multiplica as matrizes A e B e guarda o resultado em matrizC
          if(matrizC != NULL) // se a matriz C foi criada corretamente
          {
            printf("Matriz C:\n");
            ImprimirMatriz(matrizC); // imprime a matriz C
            printf("\n");
          }
          else
          {
            printf("Falha na multiplicacao das matrizes!\n");
          }
        }
        else if(!matrizA)
        {
          printf("A matriz A nao existe! Nao e possivel realizar a multiplicacao!\n");
        }
        else if(!matrizB)
        {
          printf("A matriz B nao existe! Nao e possivel realizar a multiplicacao!\n");
        }
        else
        {
          printf("Ambas as matrizes A e B nao existem! Nao e possivel realizar a multiplicacao!\n");
        }
        break;

      case 7:  // imprimir
        printf("Qual matriz deseja imprimir?\n");
        printf("Selecione 1 caso queira imprimir a Matriz A.\nSelecione 2 caso queira imprimir a matriz B.\n");
        scanf("%d", &n);

        switch(n)
        {
          case 1:
            if(matrizA != NULL)
            {
              printf("Matriz A:\n");
              ok = ImprimirMatriz(matrizA);
              if(!ok)
              {
                printf("Ocorreu um erro ao imprimir!\n");
              }
            }
            else
            {
              printf("A matriz A nao existe!\n");
            }
            break;

          case 2:
            if(matrizB != NULL)
            {
              printf("Matriz B:\n");
              ok = ImprimirMatriz(matrizB);
              if(!ok)
              {
                printf("Ocorreu um erro ao imprimir!\n");
              }
            }
            else
            {
              printf("A matriz B nao existe!\n");
            }
            break;

          default:
            printf("Opcao invalida!\n");
            break;
        }

        break;

      default:
        printf("Opcao Invalida!\n");
        break;
    }

  }while(opcao != 0);

  return 0;
}