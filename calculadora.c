//Cabeçalho:
//Aluno: Luiz Felipe Pessoa de Arruda
//Terceiro Período B
//Questão 1a: (22/08/2024) - 08:24
//Questão 1b: (22/08/2024) - 10: 50
//Questão 1c: (23/08/2024) - 10:16
//Questão 1d: (26/08/2024) - 9:40
//Questão 2: (28/08/2024) - 08:32
//Questão 3: (28/08/2024) - 10:18

#include <stdio.h>
#include <string.h>

void converterParaBinario(unsigned long long valor, int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d", (valor >> i) & 1);
    }
}

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

void DecimalBCD(int n) {
    if (n < 0) {
        printf("Número inválido. Apenas números não-negativos são suportados.\n");
        return;
    }

    if (n == 0) {
        printf("Código BCD de %d: 0000\n", n);
        return;
    }

    int digitos[10];
    int i = 0;

    while (n > 0) {
        digitos[i] = n % 10;
        n = n / 10;
        i++;
    }

    printf("Código BCD: ");
    for (int j = i - 1; j >= 0; j--) {
        int digito = digitos[j];
        for (int k = 3; k >= 0; k--) {
            printf("%d", (digito >> k) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

void DecimalComplemento2(int n) {
    if (n < -32768 || n > 32767) {
        printf("Número fora do intervalo de 16 bits com sinal.\n");
        return;
    }

    unsigned int complemento2;

    if (n < 0) {
        complemento2 = (~(-n) + 1) & 0xFFFF;
    } else {
        complemento2 = n & 0xFFFF;
    }

    printf("Passo a passo da conversão de %d para complemento de 2 com 16 bits:\n", n);
    printf("Resultado: ");

    for (int i = 15; i >= 0; i--) {
        printf("%d", (complemento2 >> i) & 1);
    }
    printf("\n");
}

void RealFloat(float num) {
    unsigned int bits;
    memcpy(&bits, &num, sizeof(bits));

    int sinal = (bits >> 31) & 1;
    int expoente = (bits >> 23) & 0xFF;
    unsigned int fracao = bits & 0x7FFFFF;

    printf("Número: %f\n", num);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d (0x%X) em binário: ", expoente - 127, expoente);
    converterParaBinario(expoente, 8);
    printf("\nFração em binário: ");
    converterParaBinario(fracao, 23);
    printf("\n");
}

void RealDouble(double num) {
    unsigned long long bits;
    memcpy(&bits, &num, sizeof(bits));

    int sinal = (bits >> 63) & 1;
    int expoente = (bits >> 52) & 0x7FF;
    unsigned long long fracao = bits & 0xFFFFFFFFFFFFF;

    printf("Número: %lf\n", num);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d (0x%X) em binário: ", expoente - 1023, expoente);
    converterParaBinario(expoente, 11);
    printf("\nFração em binário: ");
    converterParaBinario(fracao, 52);
    printf("\n");
}

int main() {
    int opcao = 0, num;
    float fnum;
    double dnum;
    while(opcao != 8) {
        printf("Calculadora Programador Didática\n");
        printf("1 - Converter base 10 para base 2\n");
        printf("2 - Converter base 10 para base 8\n");
        printf("3 - Converter base 10 para base 16\n");
        printf("4 - Converter base 10 para Código BCD\n");
        printf("5 - Converter base 10 para complemento de 2 com 16 bits\n");
        printf("6 - Converter número real para formato float\n");
        printf("7 - Converter número real para formato double\n");
        printf("8 - Sair\n");

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
            case 4:
                printf("Digite o número em base 10: ");
                scanf("%d", &num);
                DecimalBCD(num);
                break;
            case 5:
                printf("Digite o número em base 10 (com sinal): ");
                scanf("%d", &num);
                DecimalComplemento2(num);
                break;
            case 6:
                printf("Digite o número real: ");
                scanf("%f", &fnum);
                RealFloat(fnum);
                break;
            case 7:
                printf("Digite o número real: ");
                scanf("%lf", &dnum);
                RealDouble(dnum);
                break;
            case 8:
                break;
            default:
                printf("Opção inválida!\n");
                return 1;
        }
    }

    return 0;
}
