#include <stdio.h>
#include <locale.h>

int multNumero(int vetor[], int tamanho){
	int mult = 1;
	
	for (int i = 0; i < tamanho; i++){
		mult *= vetor[i];
	}
	
	return mult;
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    int mult = multNumero(vetor, tamanho);
    printf("O produto dos elementos do vetor é: %d\n", mult);

    return 0;
}
