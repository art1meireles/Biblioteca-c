#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "livro.h"

Livro livros[MAX_LIVROS];
int total_livros = 0;

void ler_texto(char *destino) {
    scanf(" %99[^\n]", destino);
}

int contem(const char *texto, const char *termo) {
    int tam_texto = strlen(texto);
    int tam_termo = strlen(termo);

    for (int i = 0; i <= tam_texto - tam_termo; i++) {
        int igual = 1;

        for (int j = 0; j < tam_termo; j++) {
            if (texto[i + j] != termo[j]) {
                igual = 0;
                break;
            }
        }

        if (igual) {
            return 1;
        }
    }

    return 0;
}

int procurar_por_id(int id) {
    for (int i = 0; i < total_livros; i++) {
        if (livros[i].id == id) {
            return i;
        }
    }
    return -1;
}

void cadastrar_livro(void) {
    if (total_livros >= MAX_LIVROS) {
        printf("Biblioteca cheia! Nao e possivel cadastrar mais livros.\n");
        return;
    }

    Livro novo;
    novo.id = total_livros + 1;

    printf("Titulo: ");
    ler_texto(novo.titulo);

    printf("Autor: ");
    ler_texto(novo.autor);

    printf("Ano: ");
    scanf("%d", &novo.ano);
    getchar();

    novo.emprestado = 0;

    livros[total_livros] = novo;
    total_livros++;

    printf("Livro cadastrado com sucesso! (id = %d)\n", novo.id);
}

void listar_livros(void) {
    if (total_livros == 0) {
        printf("Nenhum livro cadastrado ainda.\n");
        return;
    }

    printf("\n%-4s %-30s %-20s %-6s %-12s\n", "ID", "TITULO", "AUTOR", "ANO", "STATUS");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < total_livros; i++) {
        printf("%-4d %-30s %-20s %-6d %-12s\n",
               livros[i].id,
               livros[i].titulo,
               livros[i].autor,
               livros[i].ano,
               livros[i].emprestado ? "Emprestado" : "Disponivel");
    }
}

void buscar_livro(void) {
    char termo[TAM_TEXTO];
    printf("Digite parte do titulo: ");
    ler_texto(termo);

    int encontrou = 0;
    for (int i = 0; i < total_livros; i++) {
        if (contem(livros[i].titulo, termo)) {
            printf("[%d] %s - %s (%d) - %s\n",
                   livros[i].id, livros[i].titulo, livros[i].autor,
                   livros[i].ano, livros[i].emprestado ? "Emprestado" : "Disponivel");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum livro encontrado com esse termo.\n");
    }
}

void emprestar_livro(void) {
    int id;
    printf("Digite o ID do livro: ");
    scanf("%d", &id);
    getchar();

    int idx = procurar_por_id(id);
    if (idx == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (livros[idx].emprestado) {
        printf("Esse livro ja esta emprestado.\n");
        return;
    }

    livros[idx].emprestado = 1;
    printf("Livro \"%s\" emprestado com sucesso.\n", livros[idx].titulo);
}

void devolver_livro(void) {
    int id;
    printf("Digite o ID do livro: ");
    scanf("%d", &id);
    getchar();

    int idx = procurar_por_id(id);
    if (idx == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (!livros[idx].emprestado) {
        printf("Esse livro nao estava emprestado.\n");
        return;
    }

    livros[idx].emprestado = 0;
    printf("Livro \"%s\" devolvido com sucesso.\n", livros[idx].titulo);
}

void remover_livro(void) {
    int id;
    printf("Digite o ID do livro: ");
    scanf("%d", &id);
    getchar();

    int idx = procurar_por_id(id);
    if (idx == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    for (int i = idx; i < total_livros - 1; i++) {
        livros[i] = livros[i + 1];
    }
    total_livros--;

    printf("Livro removido com sucesso.\n");
}

void salvar_em_arquivo(void) {
    FILE *arquivo = fopen("livros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    for (int i = 0; i < total_livros; i++) {
        fprintf(arquivo, "%d;%s;%s;%d;%d\n",
                livros[i].id, livros[i].titulo, livros[i].autor,
                livros[i].ano, livros[i].emprestado);
    }

    fclose(arquivo);
    printf("Dados salvos em livros.txt\n");
}

void carregar_do_arquivo(void) {
    FILE *arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        return;
    }

    while (total_livros < MAX_LIVROS &&
           fscanf(arquivo, "%d;%99[^;];%99[^;];%d;%d\n",
                  &livros[total_livros].id,
                  livros[total_livros].titulo,
                  livros[total_livros].autor,
                  &livros[total_livros].ano,
                  &livros[total_livros].emprestado) == 5) {
        total_livros++;
    }

    fclose(arquivo);
}