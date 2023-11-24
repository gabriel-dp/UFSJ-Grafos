# 🗺 Cobertura _minimal_ de Vértices

___Gabriel de Paula Meira - 222050003___

A cobertura de vértices em teoria dos grafos envolve selecionar um conjunto de vértices de um grafo, de modo que cada aresta tenha pelo menos um dos vértices selecionados.

Não é possível resolver o problema em tempo polinomial, dessa forma, a melhor solução é desenvolver heurísticas que vão encontrar uma solução aproximada da realidade.

&nbsp;

## 🧠 Heurística

A heurística adotada para resolver o problema em tempo polinomial segue um raciocínio simples:

- Ordenar os vértices pela quantidade de vizinhos;
- Em ordem crescente, analisar cada um a partir dos vértices com mais de um vizinho, verificando se é possível adicionar à cobertura de vértices atual;
- Por fim, repetir o processo anterior para os vértices que possuem apenas um vizinho.

A ideia de deixar por último vértices com apenas um vizinho se torna eficaz pois em um grafo conexo esse vizinho se conecta a 2 ou mais vértices.

&nbsp;

## 🖥 Rodando o programa

[` > Ver main.cpp < `](./main.cpp)
[` > Ver graph.hpp < `](./graph.hpp)
[` > Ver gml.hpp < `](./gml.hpp)
[` > Ver vertex_cover.hpp < `](./vertex_cover.hpp)

Para compilar o programa basta possuir o compilador G++ para o código-fonte que está na linguagem C++.

Utilize o comando:

```bash
g++ main.cpp -o main
```

Em seguida execute com um arquivo de teste, informando o arquivo `.gml` de entrada:

```bash
./main tests/sjdr.gml
```

&nbsp;

## 🧪 Testes de Execução

[`> Ver pasta ./tests <`](./tests)

A entrada do programa consiste na leitura de um arquivo `.gml` com estrutura similar à exibida abaixo. As cadeias de caracteres `label` e `name` não possuem influência, podendo inclusive ser omitidas.

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
    name "-"
  ]
]
```
