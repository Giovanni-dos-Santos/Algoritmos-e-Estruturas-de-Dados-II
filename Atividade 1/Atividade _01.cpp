#include <stdio.h>
#include <locale.h>

int main() {
    int pontos[3][5], soma[3] = {0}, vencedor = 0;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite as notas dos 3 jogadores (5 notas por jogador):\n");
    for (int i = 0; i < 3; i++) {
        printf("Jogador %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%d", &pontos[i][j]);
            soma[i] += pontos[i][j];
        }
    }

    for (int i = 1; i < 3; i++) {
        if (soma[i] > soma[vencedor]) {
            vencedor = i; 
        }
    }

    printf("\nPontuação dos jogadores:\n");
    for (int i = 0; i < 3; i++) {
        printf("Jogador %d: %d pontos\n", i + 1, soma[i]);
    }

    printf("\nVencedor: Jogador %d com %d pontos\n", vencedor + 1, soma[vencedor]);

    return 0;
}
