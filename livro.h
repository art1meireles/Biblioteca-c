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

extern Livro livros[MAX_LIVROS];
extern int total_livros;

void ler_texto(char *destino);
int contem(const char *texto, const char *termo);
int procurar_por_id(int id);

void cadastrar_livro(void);
void listar_livros(void);
void buscar_livro(void);
void emprestar_livro(void);
void devolver_livro(void);
void remover_livro(void);

void salvar_em_arquivo(void);
void carregar_do_arquivo(void);

#endif