#include <stdio.h>
#include <locale.h>

int OrdemInversa (int vetor[]){
	for(int i = 9; i >= 0; i--){
		printf("%d\n", vetor[i]);
	}
}

	
int main() {
	
	setlocale(LC_ALL, "Portuguese");
	int vetor[10];
	for(int i = 0; i < 10; i++){
		scanf("%d", &vetor[i]);
	}

	printf("Números em ordem inversa:\n");
	OrdemInversa(vetor);
}
