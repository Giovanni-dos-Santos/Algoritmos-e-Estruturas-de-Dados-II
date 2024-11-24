float somar_valores(int vetor[], int tamanho) {
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para o índice %d: ", i);
        scanf("%d", &vetor[i]);
    }

    float soma = somar_valores(vetor, tamanho);
    float media = soma / tamanho;

    printf("A soma dos valores é: %.2f\n", soma);
    printf("A média dos valores é: %.2f\n", media);

    return 0;
}
