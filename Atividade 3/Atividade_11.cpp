#include <stdio.h>
#include <locale.h>

int menorNumero(int num1, int num2, int num3){
	int menor;
	if (num1 <= num2 && num1 <= num3){
		menor = num1;		
	} else if (num2 <= num1 && num2 <= num3){
		menor = num2;
	} else {
		menor = num3;
	}
	return menor;
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	int num1, num2, num3;
	
	printf("Digite 3 números inteiros: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	
	
	int menor = menorNumero(num1, num2, num3);
	printf("O menor numero é: %d", menor);
	return 0;
}
