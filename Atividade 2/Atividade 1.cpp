#include <stdio.h>
#include <locale.h>

// Fun��o para verificar se um n�mero � primo
int primo(int numero) {
    if (numero < 2) {
        return 0;  // Falso, n�o � primo
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;  // Falso, n�o � primo
        }
    }
    return 1;  // Verdadeiro, � primo
}

// Fun��o para calcular a soma dos N primeiros n�meros primos
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

// Fun��o principal (main)
int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Digite a quantidade de n�meros primos a serem somados: ");
    scanf("%d", &n);

    int resultado = somaPrimos(n);
    printf("A soma dos %d primeiros n�meros primos �: %d\n", n, resultado);

    return 0;
}
