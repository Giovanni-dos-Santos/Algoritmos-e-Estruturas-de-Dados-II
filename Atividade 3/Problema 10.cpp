#include <stdio.h>
#include <locale.h>

void maiorNumero(int num1, int num2){
	int maior;
	if (num1 == num2){
		printf("Os n�meros s�o iguais\n");
	}else if (num1 >= num2){
		printf("O maior n�mero �: %d\n", num1);
	}else {
		printf("O maior n�mero �: %d\n", num2);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	int num1, num2;
	
	printf("Digite dois n�meros inteiros: ");
	scanf("%d %d", &num1, &num2);
	
	maiorNumero(num1, num2);
	return 0;
}
	
