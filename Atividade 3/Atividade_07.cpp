void encontrar_maior_valor(int vetor[], int tamanho, int *maior, int *posicao) {
    *maior = vetor[0];
    *posicao = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > *maior) {
            *maior = vetor[i];
            *posicao = i;
        }
    }
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

    int maior, posicao;
    encontrar_maior_valor(vetor, tamanho, &maior, &posicao);

    printf("O maior valor é: %d\n", maior);
    printf("A posição do maior valor no vetor é: %d\n", posicao);

    return 0;
}
