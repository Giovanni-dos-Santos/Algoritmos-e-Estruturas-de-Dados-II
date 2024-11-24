// Giovanni dos Santos

#include <stdio.h>
#include <locale>

int somatorio(int n) {
    int soma = 0;

    for (int i = 1; i <= n; i++) {
        soma += (5 * i * i + 2 * i + 8);
    }

    return soma;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
	int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int resultado = somatorio(n);
    printf("O resultado do somatório é: %d\n", resultado);

    return 0;
}
