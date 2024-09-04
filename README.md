# SCC0210 - Laboratório de Algoritmos Avançados I

Este repositório contém os códigos e casos de teste para a disciplina **SCC0210 - Laboratório de Algoritmos Avançados I** oferecida pela Universidade de São Paulo (USP).

## Estrutura do Repositório

O repositório está organizado em diretórios, cada um representando um módulo ou tópico abordado na disciplina. Dentro de cada diretório, você encontrará os casos de teste específicos para os algoritmos desenvolvidos.

O problema e caso de teste relacionado a ele possuem o mesmo nome.

```plaintext
├───.vscode
├───01-ad-hoc
│   └───testcases
├───02-stl
│   └───testcases
├───03-guloso
│   └───testcases
├───04-backtracking
│   └───testcases
├───05-backtrackingHeuristica
│   └───testcases
├───06-divisao-e-conquista
│   └───testcases
├───07-programacao-dinamica
│   └───testcases
├───08-bitmask
│   └───testcases
├───09-teoria-dos-numeros
│   └───testcases
├───10-grafos
│   └───testcases
├───11-teoria-dos-jogos
│   └───testcases
└───12-strings
    └───testcases
```

## Descrição dos Diretórios

- 01-ad-hoc: Problemas com uso de conhecimentos elementares de programação
- 02-stl: Uso da Standard Template Library (STL) em C++. Estruturas de dados básicas (Set, Map, Priority Queue, etc)
- 03-guloso: Problemas gulosos (máximizar e míminizar sem controle de estado)
- 04-backtracking: Problemas de tentativa e erro, testar caminhos a uma solução (Força bruta)
  - O problema chess foi resolvido sem uso da técnica.
- 05-backtrackingHeuristica: Backtracking com heurísticas (Facilitador para encontrar a solução)
- 06-divisao-e-conquista: Problemas onde subproblemas definem o problema geral.
  - o problemas karatsuba está lento demais (Python)
- 07-programacao-dinamica: Problemas (onde a criança chora e o pai não vê) de otimização combinatória.
- 08-bitmask: Problemas que usam manipulação de bits.
- 09-teoria-dos-numeros: É matematiquinha, n tem jeito.
- 10-grafos: Problemas de modelagem em grafo, grafo é grafo (faz um curso inteiro disso).
- 11-teoria-dos-jogos: Problemas com uso de técnicas da Teoria dos Jogos (Grundy).
- 12-strings: Problemas de manipulação em string

## Casos de Teste

Cada módulo contém uma pasta testcases que inclui arquivos de entrada (.in) e saída (.out) para testar os algoritmos. Os casos de teste estão organizados e prontos para serem utilizados com o script de execução automatizada.

### Script de Execução Automatizada

Para facilitar a execução dos testes, há um script bash que pode ser utilizado para rodar os testes de forma automática. O script suporta arquivos em Python (.py) e C++ (.cpp) e utiliza arquivos .zip contendo os casos de teste.
Uso do Script

Para executar os testes, utilize o comando abaixo substituindo \<code\>.\<extension\> pelo nome do arquivo de código e \<testcaseDir\> pelo diretório de casos de teste.

```bash
./run-ex.bash <code>.<extension> <testcaseDir> [testcase]
```

Exemplo:

```bash
../run-ex.bash repintura.cpp testcases
```

Exemplo de Execução

![image](https://github.com/user-attachments/assets/64dcc161-3e4c-4c89-b806-bf93db9c4dfe)

nota: utilizando `WSL` no print.

Para executar um caso de teste específico:

```bash
../run-ex.bash repintura.cpp testcases 2
```

Resultado da Execução

![image](https://github.com/user-attachments/assets/624183f8-4157-4d4e-8ff7-0757b9262613)

O script exibe os resultados de cada caso de teste, indicando se passaram ou falharam.
Em caso de falha, a execução é interrompida e os detalhes da falha são exibidos.

## Referência

Para mais informações sobre a disciplina, visite a [página oficial da disciplina no JúpiterWeb](https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SCC0210&codcur=55041&codhab=0)
