// Giovanni dos Santos

#include<stdio.h>
#include<locale>

int fibonacci(int n) {
    if (n < 0) {
        printf("O �ndice n�o pode ser negativo.\n");
        return -1; 
    }
    if (n == 0) return 0; 
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
	int n;

    printf("Digite o valor de n para calcular o n-�simo termo da s�rie de Fibonacci: ");
    scanf("%d", &n);

    int resultado = fibonacci(n);
    
    if (resultado != -1) {
        printf("O %d� termo da s�rie de Fibonacci �: %d\n", n, resultado);
    }

    return 0;
}
