#include <stdio.h>
#include <locale.h>

// Função para verificar se um número é primo
int primo(int numero) {
    if (numero < 2) {
        return 0;  // Falso, não é primo
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;  // Falso, não é primo
        }
    }
    return 1;  // Verdadeiro, é primo
}

// Função para calcular a soma dos N primeiros números primos
int somaPrimos(int n) {
    int soma = 0;
    int contador = 0;
    int numero = 2;

    while (contador < n) {
        if (primo(numero)) {
            soma += numero;
            contador++;
        }
        numero++;
    }

    return soma;
}

// Função principal (main)
int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Digite a quantidade de números primos a serem somados: ");
    scanf("%d", &n);

    int resultado = somaPrimos(n);
    printf("A soma dos %d primeiros números primos é: %d\n", n, resultado);

    return 0;
}
