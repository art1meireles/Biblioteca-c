# 📚 Sistema de Biblioteca em C

Programa de linha de comando para gerenciar livros de uma biblioteca:
cadastro, listagem, busca, empréstimo, devolução e remoção — com os dados
salvos em um arquivo de texto simples.

## Funcionalidades

- Cadastrar livro (título, autor, ano)
- Listar todos os livros
- Buscar livro por parte do título
- Emprestar e devolver livro
- Remover livro
- Salvar os dados em arquivo (`livros.txt`) e carregar automaticamente na próxima execução

## Estrutura do projeto

```
biblioteca/
├── livro.h    # struct Livro e a lista de funções disponíveis
├── livro.c    # implementação de todas as funções
└── main.c     # menu principal (main)
```

## Como compilar e rodar

Precisa apenas de um compilador C (`gcc`). Sem Makefile — um único comando:

```bash
gcc main.c livro.c -o biblioteca
./biblioteca
```

## Como funciona por dentro

- Os livros ficam guardados em um **array de tamanho fixo** (`Livro livros[100]`),
  criado dentro do `main()`. Não existe alocação dinâmica (`malloc`) nesse projeto.
- `livros` e `total_livros` são criados uma única vez no `main` e passados
  como **parâmetro** para as funções que precisam deles — nada de variável
  global (`extern`).
- Quando uma função precisa **alterar** `total_livros` (cadastrar, remover),
  ele é passado por **ponteiro** (`int *total_livros`). Quando só precisa
  **ler** (listar, buscar), é passado por valor.

## Formato do arquivo salvo (`livros.txt`)

Um livro por linha, campos separados por `;`:

```
1;Dom Casmurro;Machado de Assis;1899;0
2;O Cortico;Aluisio Azevedo;1890;1
```

Na ordem: `id;titulo;autor;ano;emprestado` (`emprestado` é `0` ou `1`).

## Limitações conhecidas

- Máximo de 100 livros cadastrados (`MAX_LIVROS`)
- Títulos e autores com até 99 caracteres (`TAM_TEXTO`)
- Busca não funciona se o título contiver `;` (o caractere é usado como separador no arquivo)
- Sem histórico de quem pegou cada livro emprestado, apenas o status atual

## Possíveis melhorias futuras

- Guardar o nome de quem pegou o livro emprestado
- Editar dados de um livro já cadastrado
- Trocar o array fixo por alocação dinâmica, para não ter limite de 100 livros
