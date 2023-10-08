# ⌛ PERT/CPM

___Gabriel de Paula Meira - 222050003___

*Program Evaluation and Review Technique* é uma técnica muito utilizada na Pesquisa Operacional visando uma melhor organização e otimização de um processo divido em várias atividades.

_Critical Path Method_, muito utilizado em conjunto com a PERT, consiste na análise das ligações entre etapas de um processo e apontando pontos em que são dependentes.

&nbsp;

## 🧠 Ideias

### PERT

A ideia principal do algoritmo é realizar duas BFS (Busca em Largura), a primeira para registrar os tempos mais cedo de cada vértice e a segunda para registrar os tempos mais tarde.

### CPM

Após obter o resultado dos tempos provinientes do algoritmo PERT, basta retornar os vértices que possuem os tempos mais cedo e mais tarde iguais.

&nbsp;

## 🖥 Rodando o programa

[` > Ver main.cpp < `](./main.cpp)
[` > Ver graph.hpp < `](./graph.hpp)
[` > Ver pert_cpm.hpp < `](./pert_cpm.hpp)

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

A entrada do programa consiste na leitura de um arquivo de texto contendo as atividades já com arestas artificiais adicionadas.

Cada linha deve ser composta pelos vértices de origem e destino seguidos do peso da aresta, assim como mostra o exemplo:

```txt
1 2 7
1 3 5
2 4 9
3 5 6
4 5 0
4 6 11
5 7 4
6 8 3
7 8 8
8 9 6
8 10 4
10 9 0
9 11 7
```
