#include <stdio.h>
#include <locale.h>

void media(int num1, int num2, int num3, int num4){
	int media = (num1 + num2 + num3 + num4) / 4;
	printf("\nMédia: %d\n", media);
	if(media >= 7){
		printf("APROVADO");
	} else{
		printf("REPROVADO");
	}
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	int num1, num2, num3, num4;
	
	printf("Digite as notas: ");
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
	
	media(num1, num2, num3, num4);
}
