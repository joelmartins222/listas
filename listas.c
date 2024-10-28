#include <stdio.h>
#include <stdlib.h>

void criarLista(int **lista, int *tamanho) {
    if (*lista != NULL) {
        printf("A lista foi criada.\n");
        return 0;
    }

    *lista = (int *)malloc(100 * sizeof(int));
    if (*lista == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1); 
    }

    *tamanho = 0;
    printf("Lista criada com sucesso.\n");
}

void inserirListaOrdenado(int *lista, int *tamanho) {
    if (*tamanho >= 100) {
        printf("Lista cheia! Não é possível inserir mais elementos.\n");
        return;
    }

    int valor;
    printf("Digite um valor para inserir em ordem crescente: ");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        while (getchar() != '\n');
        return;
    }

    int i = *tamanho - 1;

    while (i >= 0 && lista[i] > valor) {
        lista[i + 1] = lista[i];
        i--;
    }

    lista[i + 1] = valor;
    (*tamanho)++;
    printf("Valor %d inserido com sucesso em ordem crescente.\n", valor);
}


void exibirLista(int *lista, int tamanho) {
    if (tamanho == 0) {
        printf("Lista vazia.\n");
        return 0;
    }

    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void verificarLista(int tamanho) {
    printf("A lista possui %d elementos.\n", tamanho);
}

void buscarLista(int *lista, int tamanho) {
    if (tamanho == 0) {
        printf("Lista vazia. Não é possível buscar.\n");
        return 0;
    }

    int valor;
    printf("Digite um valor para buscar: ");

    if (scanf("%d", &valor) != 1) {
        printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        while (getchar() != '\n'); 
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            printf("Valor %d encontrado na posição %d.\n", valor, i);
            return 0;
        }
    }

    printf("Valor %d não encontrado na lista.\n", valor);
}

void excluirLista(int *lista, int *tamanho) {
    if (*tamanho == 0) {
        printf("Lista vazia. Não é possível excluir.\n");
        return;
    }

    int valor;
    printf("Digite um valor para excluir: ");

    if (scanf("%d", &valor) != 1) {
        printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        while (getchar() != '\n'); 
        return;
    }

    for (int i = 0; i < *tamanho; i++) {
        if (lista[i] == valor) {
            for (int j = i; j < *tamanho - 1; j++) {
                lista[j] = lista[j + 1];
            }
            (*tamanho)--;
            printf("Valor %d excluído com sucesso.\n", valor);
            return;
        }
    }

    printf("Valor %d não encontrado na lista.\n", valor);
}

void liberarLista(int **lista, int *tamanho) {
    free(*lista);
    *lista = NULL;
    *tamanho = 0;
    printf("Lista liberada com sucesso.\n");
}

int main(void) {
    int *lista = NULL;
    int tamanho = 0;
    int opcao;
    int continuar = 1;

    while (continuar) {
        printf("\n1. Criar lista\n");
        printf("2. Inserir lista\n");
        printf("3. Exibir lista\n");
        printf("4. Verificar lista\n");
        printf("5. Buscar lista\n");
        printf("6. Excluir lista\n");
        printf("7. Liberar lista\n");
        printf("8. Sair do programa\n");
        

        printf("\nEscolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Erro: entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (opcao) {
            case 1:
                criarLista(&lista, &tamanho);
                break;
            case 2:
                if (lista == NULL) {
                    printf("Você precisa criar a lista primeiro.\n");
                } else {
                    inserirListaOrdenado(lista, &tamanho);
                }
                break;
            case 3:
                if (lista == NULL) {
                    printf("A lista está vazia. Crie uma lista primeiro.\n");
                } else {
                    exibirLista(lista, tamanho);
                }
                break;
            case 4:
                verificarLista(tamanho);
                break;
            case 5:
                if (lista == NULL) {
                    printf("A lista está vazia. Crie uma lista primeiro.\n");
                } else {
                    buscarLista(lista, tamanho);
                }
                break;
            case 6:
                if (lista == NULL) {
                    printf("A lista está vazia. Crie uma lista primeiro.\n");
                } else {
                    excluirLista(lista, &tamanho);
                }
                break;
            case 7:
                liberarLista(&lista, &tamanho);
                break;
            case 8:
                printf("Saindo do programa.\n");
                if (lista != NULL) {
                    liberarLista(&lista, &tamanho);
                }
                continuar = 0;
                break;
            

            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
