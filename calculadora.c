//Cabeçalho:
//Aluno: Luiz Felipe Pessoa de Arruda
//Terceiro Período B
//(26/08/2024)

#include <stdio.h>

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

void DecimalOctal(int n) {
    if (n < 0) {
        printf("Número inválido. Apenas números não-negativos são suportados.\n");
        return;
    }

    int octal[32];
    int i = 0;

    if (n == 0) {
        printf("Resultado em Octal: 0\n");
        return;
    }

    printf("Passo a passo da conversão de %d para octal:\n", n);

    while (n > 0) {
        octal[i] = n % 8;
        printf("%d / 8 = %d, resto = %d\n", n, n / 8, octal[i]);
        n = n / 8;
        i++;
    }

    printf("Resultado em Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void DecimalHexadecimal(int n) {
    if (n < 0) {
        printf("Número inválido. Apenas números não-negativos são suportados.\n");
        return;
    }

    char hexadecimal[32];
    int i = 0;
    int resto;

    if (n == 0) {
        printf("Resultado em Hexadecimal: 0\n");
        return;
    }

    printf("Passo a passo da conversão de %d para hexadecimal:\n", n);

    while (n > 0) {
        resto = n % 16;
        if (resto < 10)
            hexadecimal[i] = '0' + resto;
        else
            hexadecimal[i] = 'A' + (resto - 10);
        printf("%d / 16 = %d, resto = %c\n", n, n / 16, hexadecimal[i]);
        n = n / 16;
        i++;
    }

    printf("Resultado em Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

int main() {
    int opcao, num;

    printf("Calculadora Programador Didática\n");
    printf("1 - Converter base 10 para base 2\n");
    printf("2 - Converter base 10 para base 8\n");
    printf("3 - Converter base 10 para base 16\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o número em base 10: ");
            scanf("%d", &num);
            DecimalBinario(num);
            break;
        case 2:
            printf("Digite o número em base 10: ");
            scanf("%d", &num);
            DecimalOctal(num);
            break;
        case 3:
            printf("Digite o número em base 10: ");
            scanf("%d", &num);
            DecimalHexadecimal(num);
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    return 0;
}
