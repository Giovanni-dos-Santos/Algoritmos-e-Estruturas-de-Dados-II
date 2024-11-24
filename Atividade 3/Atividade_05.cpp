void exibir_impares(int limite) {
    printf("N�meros �mpares de 1 at� %d (exceto m�ltiplos de 7):\n", limite);
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

    printf("Digite um n�mero: ");
    scanf("%d", &numero);

    exibir_impares(numero);

    return 0;
}
