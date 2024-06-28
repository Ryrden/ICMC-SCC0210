# SCC0210 - Laboratório de Algoritmos Avançados I

Este repositório contém os códigos e casos de teste para a disciplina **SCC0210 - Laboratório de Algoritmos Avançados I** oferecida pela Universidade de São Paulo (USP).

## Estrutura do Repositório

O repositório está organizado em diretórios, cada um representando um módulo ou tópico abordado na disciplina. Dentro de cada diretório, você encontrará os casos de teste específicos para os algoritmos desenvolvidos.

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

- 01-ad-hoc: Algoritmos ad-hoc.
- 02-stl: Uso de Standard Template Library (STL) em C++.
- 03-guloso: Algoritmos gulosos.
- 04-backtracking: Algoritmos de backtracking.
- 05-backtrackingHeuristica: Backtracking com heurísticas.
- 06-divisao-e-conquista: Algoritmos de divisão e conquista.
- 07-programacao-dinamica: Algoritmos de programação dinâmica.
- 08-bitmask: Algoritmos que utilizam bitmask.
- 09-teoria-dos-numeros: Algoritmos relacionados à teoria dos números.
- 10-grafos: Algoritmos de grafos.
- 11-teoria-dos-jogos: Algoritmos de teoria dos jogos.
- 12-strings: Algoritmos de manipulação de strings.

## Casos de Teste

Cada módulo contém uma pasta testcases que inclui arquivos de entrada (.in) e saída (.out) para testar os algoritmos. Os casos de teste estão organizados e prontos para serem utilizados com o script de execução automatizada.
Script de Execução Automatizada

Para facilitar a execução dos testes, há um script bash que pode ser utilizado para rodar os testes de forma automática. O script suporta arquivos em Python (.py) e C++ (.cpp) e utiliza arquivos .zip contendo os casos de teste.
Uso do Script

Para executar os testes, utilize o comando abaixo substituindo \<code\>.\<extension\> pelo nome do arquivo de código e \<testcaseDir\> pelo diretório de casos de teste.

```bash
./run-ex.bash <code>.<extension> <testcaseDir> [testcase]
```

Exemplo:

```bash
./run-ex.bash 03-guloso.py 03-guloso/testcases
```

Exemplo de Execução

Imagem

Para executar um caso de teste específico:

```bash
./run-ex.bash 03-guloso.py 03-guloso/testcases 1
```

Resultado da Execução

O script exibe os resultados de cada caso de teste, indicando se passaram ou falharam.
Em caso de falha, a execução é interrompida e os detalhes da falha são exibidos.

## Referência

Para mais informações sobre a disciplina, visite a [página oficial da disciplina no JúpiterWeb](https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SCC0210&codcur=55041&codhab=0)
