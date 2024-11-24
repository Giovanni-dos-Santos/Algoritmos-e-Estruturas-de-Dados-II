#include <stdio.h>
#include <locale.h>

void maiorNumero(int num1, int num2){
	int maior;
	if (num1 == num2){
		printf("Os números são iguais\n");
	}else if (num1 >= num2){
		printf("O maior número é: %d\n", num1);
	}else {
		printf("O maior número é: %d\n", num2);
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	int num1, num2;
	
	printf("Digite dois números inteiros: ");
	scanf("%d %d", &num1, &num2);
	
	maiorNumero(num1, num2);
	return 0;
}
	
