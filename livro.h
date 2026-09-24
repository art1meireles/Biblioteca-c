#ifndef LIVRO_H
#define LIVRO_H

#define MAX_LIVROS 100
#define TAM_TEXTO 100

typedef struct {
    int id;
    char titulo[TAM_TEXTO];
    char autor[TAM_TEXTO];
    int  ano;
    int  emprestado;
} Livro;

void ler_texto(char *destino);
int contem(const char *texto, const char *termo);
int procurar_por_id(Livro livros[], int total_livros, int id);

void cadastrar_livro(Livro livros[], int *total_livros);
void listar_livros(Livro livros[], int total_livros);
void buscar_livro(Livro livros[], int total_livros);
void emprestar_livro(Livro livros[], int total_livros);
void devolver_livro(Livro livros[], int total_livros);
void remover_livro(Livro livros[], int *total_livros);

void salvar_em_arquivo(Livro livros[], int total_livros);
void carregar_do_arquivo(Livro livros[], int *total_livros);

#endif