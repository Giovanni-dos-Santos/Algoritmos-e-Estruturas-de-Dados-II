
// Giovanni dos Santos

#include <stdio.h>
#include <locale>
float mediaTurma(int numAlunos) {
    float soma = 0.0;
    float nota;

    for (int i = 0; i < numAlunos; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &nota);
        soma += nota;
    }

    return soma / numAlunos;
}

float mediaEscola(int numTurmas) {
    float somaMediaTurmas = 0.0;
    int numAlunos;
    
    for (int i = 0; i < numTurmas; i++) {
        printf("Digite o n�mero de alunos da turma %d: ", i + 1);
        scanf("%d", &numAlunos);

        if (numAlunos > 0) {
            float mediaTurmaAtual = mediaTurma(numAlunos);
            printf("A m�dia da turma %d �: %.2f\n", i + 1, mediaTurmaAtual);
            somaMediaTurmas += mediaTurmaAtual;
        } else {
            printf("N�mero de alunos deve ser maior que zero.\n");
            i--;
        }
    }

    return somaMediaTurmas / numTurmas;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int numTurmas;

    printf("Digite o n�mero de turmas: ");
    scanf("%d", &numTurmas);

    if (numTurmas > 0) {
        float mediaGeral = mediaEscola(numTurmas);
        printf("A m�dia geral da escola �: %.2f\n", mediaGeral);
    } else {
        printf("N�mero de turmas deve ser maior que zero.\n");
    }

    return 0;
}
