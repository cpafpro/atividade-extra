#include <stdio.h>
#include <stdlib.h>

// Atividade 3: struct Produto
typedef struct {
    int   id;
    float preco;
} Produto;

// Atividade 2: desconto com ponteiro para float
void aplicar_desconto_v1(float *preco, float percentual) {
    *preco = *preco * (1.0f - percentual / 100.0f);
}

// Atividade 3: desconto com ponteiro para struct
void aplicar_desconto(Produto *p, float percentual) {
    p->preco = p->preco * (1.0f - percentual / 100.0f);
}

// Atividade 4: impressão com aritmética de ponteiros
void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("\n%-5s  %-10s\n", "ID", "Preco (R$)");
    printf("%-5s  %-10s\n", "---", "----------");
    for (int i = 0; i < quantidade; i++) {
        printf("%-5d  %.2f\n", (ptr + i)->id, (ptr + i)->preco);
    }
    printf("\n");
}

int main(void) {

    // Atividade 1
    printf("=== Atividade 1: Modificacao via ponteiro ===\n");
    float preco = 100.0f;
    float *ptr_preco = &preco;
    printf("Preco original  : R$ %.2f\n", preco);
    *ptr_preco = *ptr_preco * 1.10f;
    printf("Preco apos +10%%: R$ %.2f\n\n", preco);

    // Atividade 2
    printf("=== Atividade 2: Desconto via funcao ===\n");
    float preco_camisa = 80.0f;
    printf("Preco antes do desconto: R$ %.2f\n", preco_camisa);
    aplicar_desconto_v1(&preco_camisa, 15.0f);
    printf("Preco apos 15%% de desconto: R$ %.2f\n\n", preco_camisa);

    // Atividade 3
    printf("=== Atividade 3: Ponteiro para struct ===\n");
    Produto notebook = {42, 3500.0f};
    Produto *ptr_prod = &notebook;
    printf("Produto id=%d | preco original  : R$ %.2f\n", ptr_prod->id, ptr_prod->preco);
    aplicar_desconto(ptr_prod, 20.0f);
    printf("Produto id=%d | preco c/ 20%% desc: R$ %.2f\n\n", ptr_prod->id, ptr_prod->preco);

    // Atividade 4
    printf("=== Atividade 4: Array estatico de Produtos ===\n");
    Produto estoque[3] = {
        {1, 49.90f},
        {2, 129.99f},
        {3, 299.00f}
    };
    printf("Estoque inicial:");
    imprimir_produtos(estoque, 3);
    aplicar_desconto(estoque + 1, 10.0f);
    printf("Apos 10%% de desconto no produto 2:");
    imprimir_produtos(estoque, 3);

    // Atividade 5
    printf("=== Atividade 5: Alocacao dinamica ===\n");
    int n;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numero invalido.\n");
        return 1;
    }

    Produto *catalogo = (Produto *) malloc(n * sizeof(Produto));
    if (catalogo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n[Produto %d]\n", i + 1);
        printf("  ID   : ");
        scanf("%d", &(catalogo + i)->id);
        printf("  Preco: ");
        scanf("%f", &(catalogo + i)->preco);
    }

    printf("\nCatalogo cadastrado:");
    imprimir_produtos(catalogo, n);

    free(catalogo);
    catalogo = NULL;

    printf("Memoria liberada com sucesso.\n");
    return 0;
}
