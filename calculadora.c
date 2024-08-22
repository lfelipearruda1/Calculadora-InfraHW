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
            hexadecimal[i] = 48 + resto; // '0' a '9'
        else
            hexadecimal[i] = 55 + resto; // 'A' a 'F'
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

void DecimalBCD(int n) {
    if (n < 0) {
        printf("Número inválido. Apenas números não-negativos são suportados.\n");
        return;
    }

    if (n == 0) {
        printf("Código BCD de %d: 0000\n", n);
        return;
    }

    printf("Código BCD de %d: ", n);

    int digito;
    int bcd[4];
    while (n > 0) {
        digito = n % 10;
        for (int i = 3; i >= 0; i--) {
            bcd[i] = (digito >> i) & 1;
            printf("%d", bcd[i]);
        }
        printf(" ");
        n = n / 10;
    }
    printf("\n");
}

int main() {
    int opcao, num;

    printf("Calculadora Programador Didática\n");
    printf("Escolha uma das opções abaixo:\n");
    printf("1 - Converter base 10 para base 2\n");
    printf("2 - Converter base 10 para base 8\n");
    printf("3 - Converter base 10 para base 16\n");
    printf("4 - Converter base 10 para Código BCD\n");

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 4) {
        printf("Opção inválida!\n");
        return 1;
    }

    printf("Digite o número em base 10: ");
    scanf("%d", &num);

    switch (opcao) {
        case 1:
            DecimalBinario(num);
            break;
        case 2:
            DecimalOctal(num);
            break;
        case 3:
            DecimalHexadecimal(num);
            break;
        case 4:
            DecimalBCD(num);
            break;
    }

    return 0;
}
