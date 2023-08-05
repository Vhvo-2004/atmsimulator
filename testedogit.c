#include <stdio.h>
//Colocanddo comentario pra teste do git Status
float saldo = 0;

void deposito(float valor) {
    saldo += valor;
    printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
}

void saque(float valor) {
    if (valor <= saldo) {
        saldo -= valor;
        printf("\nSaque de R$ %.2f realizado com sucesso!\n", valor);

        int notas[] = {100, 50, 20, 10, 5, 2, 1};
        int moedas[] = {50, 25, 10, 5, 1};
        int qtdNotas, qtdMoedas, i;

        printf("Notas:\n");
        for (i = 0; i < 7; i++) {
            qtdNotas = valor / notas[i];
            valor = valor - (qtdNotas * notas[i]);
            printf("%d nota(s) de R$ %d\n", qtdNotas, notas[i]);
        }

        printf("Moedas:\n");
        for (i = 0; i < 5; i++) {
            qtdMoedas = valor / moedas[i];
            valor = valor - (qtdMoedas * moedas[i]);
            printf("%d moeda(s) de R$ %.2f\n", qtdMoedas, moedas[i] / 100.0);
        }
    } else {
        printf("Saldo insuficiente para o saque.\n");
    }
}

float verificarSaldo() {
    return saldo;
}

int main() {
    int opcao;
    float valor;

    while (1) {
        printf("\nEscolha uma opçao:\n");
        printf("1 - Deposito\n");
        printf("2 - Saque\n");
        printf("3 - Verificar Saldo\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor do deposito: ");
                scanf("%f", &valor);
                deposito(valor);
                break;

            case 2:
                printf("Digite o valor do saque: ");
                scanf("%f", &valor);
                saque(valor);
                break;

            case 3:
                printf("Saldo atual: R$ %.2f\n", verificarSaldo());
                break;

            case 4:
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
