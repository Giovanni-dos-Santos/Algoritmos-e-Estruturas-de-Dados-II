void exibir_impares(int limite) {
    printf("Números ímpares de 1 até %d (exceto múltiplos de 7):\n", limite);
    for (int i = 1; i <= limite; i++) {
        if (i % 2 != 0 && i % 7 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    exibir_impares(numero);

    return 0;
}
