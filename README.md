# Simulacao de Busca e Ordenacao de Livros

## Identificacao

| Item | Informacao |
|---|---|
| Disciplina | Estrutura de Dados |
| Conteudo original | Busca Sequencial |
| Conteudo atual | Ordenacao de Registros em Arquivo |
| Aluno | Pedro Lucas Figueiredo Santana |
| Matricula | 202017049 |
| Linguagem | C |

## Visao geral

Este repositorio comecou como um trabalho da materia voltado para **Busca** e foi ampliado com uma nova entrega de **Ordenacao**.

- A parte antiga do projeto faz busca de livros em arquivo
- A parte nova organiza os mesmos livros por `ISBN`
- As duas partes continuam no mesmo repositorio, mas com executaveis separados

## Estrutura do projeto

### Parte de Busca

- `main.c`: menu principal do trabalho de busca
- `linear_search.h`: busca linear e busca com sentinela
- `get_indexes.h`: leitura do arquivo e criacao de indices por ISBN, titulo e autor
- `add_book.h`, `remove_book.h`, `refresh_append.h`: manutencao do arquivo `books.txt`
- `generate_data.h`: geracao da base inicial
- `test/busca_linear_sentinela.c`: exemplos extras de buscas lineares

### Parte de Ordenacao

- `sorting_main.c`: menu principal da parte de ordenacao
- `sorting_support.h`: leitura, copia, embaralhamento e impressao dos livros
- `sorting_algorithms.h`: implementacao dos algoritmos de ordenacao

## Algoritmos implementados

Os registros sao ordenados pelo campo `ISBN`.

- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort
- Quick Sort
- Heap Sort
- Merge Sort
- Counting Sort
- Radix Sort

## Como executar

### Rodar a Busca

```bash
gcc main.c -o main
./main
```

O programa abre um menu para inserir, remover e buscar livros no arquivo.

### Rodar a Ordenacao

```bash
gcc sorting_main.c -o sorting_main
./sorting_main
```

Opcoes mais uteis do menu:

- `10`: demonstra o Radix Sort mostrando antes e depois
- `11`: compara os 9 algoritmos usando a mesma entrada

## Como a Ordenacao funciona

Na parte de ordenacao, o programa:

1. le os livros salvos em `books.txt`
2. faz uma copia desses registros em memoria
3. embaralha essa copia para criar a entrada de teste
4. aplica o algoritmo escolhido
5. mostra o resultado ordenado pelo `ISBN`

Na opcao de comparacao, todos os algoritmos recebem a mesma lista embaralhada. Isso deixa a comparacao mais justa.

## Screenshots

![Tela 1](image.png)
![Tela 2](image-1.png)
![Tela 3](image-2.png)

## Videos

- [Video atual da entrega de Ordenacao](https://youtu.be/V84mxaMgRB4)
- [Video antigo da entrega de Busca](https://youtu.be/RfvAWosSif8)
