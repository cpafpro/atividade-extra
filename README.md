# PIF – Atividade Extra: Fundamentos de Ponteiros em C

Resolução das 5 atividades em um único arquivo `produtos.c`.

Compilar: gcc -o produtos produtos.c

## Atividades

Atividade 1 – Declara um `float preco` e um ponteiro `float *ptr_preco`. O aumento de 10% é aplicado exclusivamente via `*ptr_preco`, alterando o valor original.

Atividade 2 – A lógica de desconto é movida para a função `aplicar_desconto_v1(float *preco, float percentual)`. O endereço da variável (`&preco`) é passado como argumento, permitindo que a função altere o valor original.

Atividade 3 – Criada a `struct Produto` com campos `id` e `preco`. A função é atualizada para `aplicar_desconto(Produto *p, float percentual)`, usando o operador `->` para acessar e modificar o campo `preco`.

Atividade 4 – Array estático de 3 produtos passado para `imprimir_produtos(Produto *ptr, int quantidade)`. A iteração usa aritmética de ponteiros — `(ptr + i)->id` e `(ptr + i)->preco` — sem colchetes.

Atividade 5 – O número de produtos é lido em tempo de execução. A memória é alocada com `malloc(n * sizeof(Produto))` e liberada com `free()` ao final.
