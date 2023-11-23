# 💦 Fluxo Máximo

___Gabriel de Paula Meira - 222050003___

O problema do fluxo máximo em um grafo consiste em determinar a maior quantidade de fluxo que pode ser enviado de um ponto de origem para um ponto de destino em uma rede, considerando as capacidades das conexões entre eles. O objetivo é encontrar a rota que maximize esse fluxo, respeitando as capacidades das conexões e mantendo a conservação do fluxo nos nós intermediários.

Algoritmos como o de Ford-Fulkerson são utilizados para resolver esse problema, que tem aplicações em diversas áreas, como redes de transporte e telecomunicações.

&nbsp;

## 🧠 Ideias

O algoritmo de Ford-Fulkerson aumenta iterativamente o fluxo em uma rede ao encontrar caminhos de aumento (caminhos da fonte ao destino) e atualiza as capacidades residuais até não existirem mais caminhos de aumento possíveis, determinando assim o fluxo máximo na rede.

&nbsp;

## 🖥 Rodando o programa

[` > Ver main.cpp < `](./main.cpp)
[` > Ver graph.hpp < `](./graph.hpp)
[` > Ver pert_cpm.hpp < `](./maxflow.hpp)

Para compilar o programa basta possuir o compilador G++ para o código-fonte que está na linguagem C++.

Utilize o comando:

```bash
g++ main.cpp -o main
```

Em seguida execute com um arquivo de teste:

```bash
./main < tests/test1.in
```

&nbsp;

## 🧪 Testes de Execução

[`> Ver pasta ./tests <`](./tests)

A entrada do programa consiste na leitura de um arquivo de texto contendo as arestas.

Cada linha deve ser composta pelos vértices de origem e destino seguidos do fluxo da aresta, assim como mostra o exemplo:

```txt
0 1 16
1 3 12
3 5 20
4 3 7
4 5 4
2 4 14
3 2 9
2 1 4
0 2 13
```
