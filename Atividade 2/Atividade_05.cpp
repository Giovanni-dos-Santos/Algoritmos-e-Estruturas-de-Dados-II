// Giovanni dos Santos

#include <stdio.h>
#include <locale>

int soma(int a, int b) {
    return a + b;
}

int soma(int a, int b);

int main() {
	setlocale(LC_ALL, "Portuguese");
    int num1, num2, resultado;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);

    resultado = soma(num1, num2);

    printf("A soma de %d e %d é: %d\n", num1, num2, resultado);

    return 0;
}
