float calcularMedia(int num1, int num2, int num3) {
    return (num1 + num2 + num3) / 3.0
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int num1, num2, num3;

    printf("Digite o primeiro n�mero inteiro: ");
    scanf("%d", &num1);

    printf("Digite o segundo n�mero inteiro: ");
    scanf("%d", &num2);

    printf("Digite o terceiro n�mero inteiro: ");
    scanf("%d", &num3);

    float media = calcularMedia(num1, num2, num3);

    printf("A m�dia dos n�meros �: %.2f\n", media);

    return 0;
}