# 💪 Componentes Fortemente Conectados

___Gabriel de Paula Meira - 222050003___

Um componentes de um grafo fortemente conectados é um subconjunto de vértices que para todo par de vértices ___u___ e ___v___ existe um caminho de ___u___ para ___v___ e vice-versa.

&nbsp;

## 🧠 Ideias

A ideia principal do algoritmo é realizar uma busca para descobrir os vértices alcançáveis a partir de cada um.

Essa busca é feita no grafo recebido e no grafo inverso a ele, utilizando a interseção dos dois conjuntos encontrados para determinar quais são os componentes fortemente conectados.

&nbsp;

## 🖥 Rodando o programa

[` > Ver scc.cpp < `](./scc.cpp)

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

## 🧪 Teste de execução

[`> Ver pasta ./tests <`](./tests)

A entrada do programa consiste na leitura de um arquivo de texto contendo os caracteres respectivos a cada vértice, sendo cada linha composta pelos vértices de origem e destino separados por um espaço, assim como mostra o exemplo:

```txt
A C
B A
C B
C D
D B
```

Quatro arquivos de teste foram formulados, sendo os três primeiros do slide exibido em aula.
