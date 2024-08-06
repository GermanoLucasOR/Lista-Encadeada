#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

No* criarLista() {
    return NULL;
}

int estaVazia(No* cabeca) {
    return cabeca == NULL;
}

int obterTamanho(No* cabeca) {
    int tamanho = 0;
    No* atual = cabeca;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;
}

int obterElemento(No* cabeca, int posicao) {
    if (posicao <= 0 || posicao > obterTamanho(cabeca)) {
        printf("Posição inválida.\n");
        return -1;
    }
    No* atual = cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual->dado;
}

void modificarElemento(No* cabeca, int posicao, int novoValor) {
    if (posicao <= 0 || posicao > obterTamanho(cabeca)) {
        printf("Posição inválida.\n");
        return;
    }
    No* atual = cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }
    atual->dado = novoValor;
}

void inserirElemento(No** cabeca, int posicao, int valor) {
    if (posicao <= 0 || posicao > obterTamanho(*cabeca) + 1) {
        printf("Posição inválida.\n");
        return;
    }
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    if (posicao == 1) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    } else {
        No* atual = *cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

void retirarElemento(No** cabeca, int posicao) {
    if (posicao <= 0 || posicao > obterTamanho(*cabeca)) {
        printf("Posição inválida.\n");
        return;
    }
    No* temp;
    if (posicao == 1) {
        temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
    } else {
        No* atual = *cabeca;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        temp = atual->proximo;
        atual->proximo = temp->proximo;
    }
    free(temp);
}

void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    No* lista = criarLista();

    inserirElemento(&lista, 1, 10);
    inserirElemento(&lista, 2, 20);
    inserirElemento(&lista, 3, 30);
    inserirElemento(&lista, 2, 15);
    printf("Lista após inserções: ");
    imprimirLista(lista);

    printf("A lista está vazia? %s\n", estaVazia(lista) ? "Sim" : "Não");

    printf("Tamanho da lista: %d\n", obterTamanho(lista));

    printf("Elemento na posição 2: %d\n", obterElemento(lista, 2));

    modificarElemento(lista, 2, 25);
    printf("Lista após modificação: ");
    imprimirLista(lista);

    retirarElemento(&lista, 3);
    printf("Lista após remoção: ");
    imprimirLista(lista);

    return 0;
}
