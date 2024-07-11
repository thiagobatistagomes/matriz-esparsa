# matriz-esparsa
 Representação de Matriz Esparsa utilizando TAD Lista Encadeada Circular em C

1. Introdução

No cenário computacional, matrizes esparsas, compostas majoritariamente por elementos nulos, desafiam a eficiência de representação e manipulação. Este documento propõe a implementação de um Tipo Abstrato de Dados (TAD) de lista circular como solução para lidar com a otimização de matrizes esparsas. Tradicionalmente, a representação dessas estruturas tem sido desafiadora devido à ineficiência no armazenamento e processamento. Exploraremos a viabilidade dessa abordagem, enfocando a aplicação do TAD de lista circular para superar as limitações convencionais, oferecendo eficiência no uso de memória e operações matriciais.

2.	Breve descrição do problema abordado

A representação convencional de matrizes, especialmente as esparsas, encara um desafio considerável devido à preponderância de elementos nulos. Em situações onde a maioria dos valores em uma matriz é zero, o armazenamento convencional se mostra ineficiente, resultando no uso excessivo de memória para representar dados escassos. Esse cenário resulta em ineficiência tanto no armazenamento quanto na execução de operações matriciais, demandando uma abordagem mais eficaz para lidar com a escassez de dados em matrizes extensas, otimizando o uso de memória e agilizando as manipulações necessárias.

3.	TAD UTILIZADA

 A estrutura de dados adotada para lidar com matrizes esparsas é o Tipo Abstrato de Dados (TAD) de Lista Circular. Essa estrutura oferece uma abordagem eficiente para representar elementos não nulos da matriz, permitindo a conexão de linhas e colunas de forma circular, o que reduz significativamente a complexidade de armazenamento e possibilita operações matriciais com eficiência.

4.	Descrição das principais partes da implementação
A implementação da Matriz Esparsa utilizando uma TAD de lista circular se baseia na organização dos elementos não nulos, conectando linhas e colunas de forma circular. A implementação utiliza a estrutura TipoCelula para representar cada elemento não nulo da matriz esparsa, conectando-se por ponteiros direita (colunas) e abaixo (linhas). A struct tipomatrizesparsa armazena informações sobre as dimensões da matriz e os ponteiros para as células iniciais, finais de linha e coluna, possibilitando operações eficientes como inserção, busca e operações matriciais, aproveitando a lista circular para minimizar o uso de recursos computacionais.

5.	Como utilizar a aplicação

A aplicação apresenta um menu de opções onde o usuário é livre para criar até duas matrizes, que possibilitarão caso necessário as operações de soma e multiplicação. O menu oferece também, as opções de inserir, buscar e imprimir os valores de ambas as matrizes criadas, que serão denominadas Matriz A e Matriz B. Após finalizar todos os procedimentos, o usuário pode utilizar a opção de liberar cada uma das matrizes, no entanto, se o mesmo não quiser ou se esquecer o programa libera automaticamente a memória ao ser finalizado.

6.	Conclusão

A representação de matrizes esparsas por meio de listas circulares oferece uma solução eficiente para lidar com o desafio de elementos nulos predominantes. Essa abordagem demonstra uma manipulação mais eficaz de elementos não nulos, viabilizando operações matriciais de forma otimizada. Ao minimizar o uso de recursos computacionais, revela-se como uma alternativa promissora para aplicações que lidam com matrizes esparsas, garantindo economia de memória e processamento ágil.

7.	Referências Bibliográficas
 Vídeo aula: https://www.youtube.com/watch?v=C_ePgrEbLs0
https://edisciplinas.usp.br/pluginfile.php/4135303/mod_resource/content/1/SCC0202-aula-06-Matrizes_esparsas%20_semcodigo.pdf
