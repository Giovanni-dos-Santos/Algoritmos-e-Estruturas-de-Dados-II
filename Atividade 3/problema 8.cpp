#include <stdio.h>
#include <locale.h>

void exibirPares(int numero){
	for(int i = 1; i <= numero; i++){
		if(i % 2 == 0){
			printf("%d ", i);			
		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int numero;
	
	printf("Digite um n�mero inteiro: ");
	scanf("%d", &numero);
	
	printf("\nOs numero pares de %d s�o: ", numero);
	exibirPares(numero);
	
	return 0;
}
