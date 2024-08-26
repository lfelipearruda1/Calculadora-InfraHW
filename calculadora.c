//Cabeçalho:
//Aluno: Luiz Felipe Pessoa de Arruda
//Terceiro Período B
//(26/08/2024)

#include <stdio.h>

// Função para converter decimal para binário
void DecimalBinario(int n) {
    if (n < 0) {
        printf("Número inválido. Apenas números não-negativos são suportados.\n");
        return;
    }

    int binario[32];
    int i = 0;

    if (n == 0) {
        printf("Resultado em Binário: 0\n");
        return;
    }

    printf("Passo a passo da conversão de %d para binário:\n", n);

    while (n > 0) {
        binario[i] = n % 2;
        printf("%d / 2 = %d, resto = %d\n", n, n / 2, binario[i]);
        n = n / 2;
        i++;
    }

    printf("Resultado em Binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

int main() {
    int opcao, num;

    printf("Calculadora Programador Didática\n");
    printf("1 - Converter base 10 para base 2\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o número em base 10: ");
            scanf("%d", &num);
            DecimalBinario(num);
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    return 0;
}
