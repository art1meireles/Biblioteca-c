#include <stdio.h>
#include "livro.h"

void mostrar_menu(void) {
    printf("\n===== BIBLIOTECA =====\n");
    printf("1 - Cadastrar livro\n");
    printf("2 - Listar livros\n");
    printf("3 - Buscar livro por titulo\n");
    printf("4 - Emprestar livro\n");
    printf("5 - Devolver livro\n");
    printf("6 - Remover livro\n");
    printf("7 - Salvar e sair\n");
    printf("=======================\n");
    printf("Escolha uma opcao: ");
}

int main(void) {
    Livro livros[MAX_LIVROS];
    int total_livros = 0;

    carregar_do_arquivo(livros, &total_livros);
    printf("Biblioteca iniciada. %d livro(s) carregado(s).\n", total_livros);

    int opcao;
    int continuar = 1;

    while (continuar) {
        mostrar_menu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrar_livro(livros, &total_livros);
                break;
            case 2:
                listar_livros(livros, total_livros);
                break;
            case 3:
                buscar_livro(livros, total_livros);
                break;
            case 4:
                emprestar_livro(livros, total_livros);
                break;
            case 5:
                devolver_livro(livros, total_livros);
                break;
            case 6:
                remover_livro(livros, &total_livros);
                break;
            case 7:
                salvar_em_arquivo(livros, total_livros);
                printf("Ate logo!\n");
                continuar = 0;
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}