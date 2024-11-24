// Giovanni dos Santos

#include <stdio.h>
#include <locale>

int somaVetor(int vetor[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return soma;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int numeros[3];

    for (int i = 0; i < 3; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    int resultado = somaVetor(numeros, 3);

    printf("A soma dos valores é: %d\n", resultado);

    return 0;
}
