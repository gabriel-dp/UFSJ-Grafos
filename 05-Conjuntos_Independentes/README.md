# 👸 Conjuntos Independetes

___Gabriel de Paula Meira - 222050003___

No jogo de xadrez, a rainha é uma peça cuja movimentação se dá livremente nas linhas colunas e diagonais do tabuleiro.

Um dos problemas mais clássicos da Ciência da Computação é o problema das oito rainhas, que consiste em posicionar, simultaneamente, oito rainhas em um tabuleiro de xadrez tradicional (de tamanho 8 x 8), de forma que cada uma não fique no caminho das outras.

&nbsp;

## 🧠 Algoritmo

Foi desenvolvido um algoritmo de backtracking para encontrar uma solução válida, sendo uma opção mais viável do que a força bruta devido a evitar iterações desnecessárias caso parte da solução não satisfaça a condição do problema.

&nbsp;

## 🖥 Rodando o programa

[` > Ver main.cpp < `](./main.cpp)
[` > Ver graph.hpp < `](./graph.hpp)
[` > Ver gml.hpp < `](./gml.hpp)
[` > Ver queens.hpp < `](./queens.hpp)

Para compilar o programa basta possuir o compilador G++ para o código-fonte que está na linguagem C++.

Utilize o comando:

```bash
g++ main.cpp -o main
```

Em seguida execute com um arquivo de teste, informando o arquivo `.gml` com as  incompatibilidades do tabuleiro:

```bash
./main tests/board.gml
```

&nbsp;

## 🧪 Testes de Execução

[`> Ver pasta ./tests <`](./tests)

A entrada do programa consiste na leitura de um arquivo `.gml` com estrutura similar à exibida abaixo.

O `id` define o número da casa no tabuleiro da esquerda para a direita.

A `label` não tem impacto no funcionamento do algoritmo.

```gml
graph [
  node [
    id 0
    label "-"
  ]
  node [
    id 1
    label "-"
  ]
  edge [
    source 0
    target 1
  ]
]
```

### Saída

A primeira linha contém uma sequência com posições das rainhas que satisfazem a condição do problema. O restante das linhas representa o tabuleiro completo indicando as rainhas por um `♛`.

```txt
0 12 23 29 34 46 49 59 
[♛][ ][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][♛][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][ ][♛]
[ ][ ][ ][ ][ ][♛][ ][ ]
[ ][ ][♛][ ][ ][ ][ ][ ]
[ ][ ][ ][ ][ ][ ][♛][ ]
[ ][♛][ ][ ][ ][ ][ ][ ]
[ ][ ][ ][♛][ ][ ][ ][ ]
```

> O exemplo acima é gerado a partir do arquivo de teste [`> tests/board.gml <`](./tests/board.gml)
