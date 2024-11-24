#include <stdio.h>
#include <locale.h>
#include <string.h>

// Limite m�ximo de usu�rios
#define MAX_USERS 100

// Defini��o da estrutura do Usu�rio
struct Usuario {
    int id;
    char email[255];
    char nome[100];
    char senha[255];
};

// Array para armazenar os usu�rios e o contador
struct Usuario usuarios[MAX_USERS];
int usuarioCount = 0;

// Fun��o para salvar os usu�rios no arquivo CSV
void salvarUsuariosCSV() {
    FILE *arquivo = fopen("usuarios.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os usu�rios!\n");
        return;
    }

    fprintf(arquivo, "ID,Email,Nome,Senha\n");
    for (int i = 0; i < usuarioCount; i++) {
        fprintf(arquivo, "%d,%s,%s,%s\n", usuarios[i].id, usuarios[i].email, usuarios[i].nome, usuarios[i].senha);
    }

    fclose(arquivo);
    printf("Usu�rios salvos em 'usuarios.csv'.\n");
}

// Fun��o para carregar os usu�rios do arquivo CSV
void carregarUsuariosCSV() {
    FILE *arquivo = fopen("usuarios.csv", "r");

    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado, come�ando com zero usu�rios.\n");
        return;
    }

    char linha[500];
    fgets(linha, sizeof(linha), arquivo);

    while (fscanf(arquivo, "%d,%254[^,],%99[^,],%254[^\n]\n", &usuarios[usuarioCount].id, usuarios[usuarioCount].email, usuarios[usuarioCount].nome, usuarios[usuarioCount].senha) == 4) {
        usuarioCount++;
    }

    fclose(arquivo);
    printf("Usu�rios carregados de 'usuarios.csv'.\n");
}

// Fun��o para criar um novo usu�rio
void createUsuario(int id, const char* email, const char* nome, const char* senha) {
    if (usuarioCount >= MAX_USERS) {
        printf("Erro: Limite de usu�rios atingido.\n");
        return;
    }

    struct Usuario usuario;
    usuario.id = id;
    strcpy(usuario.email, email);
    strcpy(usuario.nome, nome);
    strcpy(usuario.senha, senha);
    usuarios[usuarioCount++] = usuario;
    printf("\nUsu�rio criado com sucesso!\n");
    salvarUsuariosCSV();
}

// Fun��o para ler um usu�rio por ID
struct Usuario* readUsuario(int id) {
    for (int i = 0; i < usuarioCount; i++) {
        if (usuarios[i].id == id) {
            return &usuarios[i];
        }
    }
    return NULL;
}

// Fun��o para atualizar um Usu�rio
void updateUsuario(int id, const char* email, const char* nome, const char* senha) {
    struct Usuario* usuario = readUsuario(id);
    if (usuario != NULL) {
        strcpy(usuario->email, email);
        strcpy(usuario->nome, nome);
        strcpy(usuario->senha, senha);
        printf("\nUsu�rio atualizado com sucesso!\n");
        salvarUsuariosCSV();
    } else {
        printf("\nUsu�rio n�o encontrado.\n");
    }
}

// Fun��o para deletar um usu�rio
void deleteUsuario(int id) {
    struct Usuario* usuario = readUsuario(id);
    if (usuario == NULL) {
        printf("\nUsu�rio n�o encontrado.\n");
        return;
    }
    int usuarioIndex = usuario - usuarios;

    for (int i = usuarioIndex; i < usuarioCount - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }
    usuarioCount--;
    printf("\nUsu�rio deletado com sucesso!\n");
    salvarUsuariosCSV();
}
// Fun��o para listar todos os usu�rios
void listarUsuarios() {
    if (usuarioCount == 0) {
        printf("\nNenhum usu�rio cadastrado.\n");
        return;
    }
    printf("\nUsu�rios cadastrados:\n");
    for (int i = 0; i < usuarioCount; i++) {
        printf("ID: %d, Email: %s, Nome: %s, Senha: %s\n", usuarios[i].id, usuarios[i].email, usuarios[i].nome, usuarios[i].senha);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    carregarUsuariosCSV();

    do {
        // Menu de op��es
        printf("\n==============================================\n");
        printf("     SISTEMA DE GERENCIAMENTO DE USU�RIOS\n");
        printf("==============================================\n");
        printf("1. Gerenciar Usu�rios\n");
        printf("2. Sair\n");
        printf("----------------------------------------------\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Menu de gerenciamento de usu�rios
            int userOption;
            do {
                printf("\n1. Adicionar Usu�rio\n");
                printf("2. Deletar Usu�rio\n");
                printf("3. Atualizar Usu�rio\n");
                printf("4. Listar Usu�rios\n");
                printf("5. Voltar ao Menu Principal\n");
                printf("Escolha uma op��o: ");
                scanf("%d", &userOption);

                if (userOption == 1) {
                    // Adicionar um novo usu�rio
                    int id;
                    char email[255], nome[100], senha[255];
                    printf("\nDigite o ID do novo usu�rio: ");
                    scanf("%d", &id);
                    printf("Digite o e-mail: ");
                    scanf(" %254[^\n]", email);
                    printf("Digite o nome: ");
                    scanf(" %99[^\n]", nome);
                    printf("Digite a senha: ");
                    scanf(" %254[^\n]", senha);
                    createUsuario(id, email, nome, senha);
                }
                else if (userOption == 2) {
                    // Deletar um usu�rio
                    int id;
                    printf("\nDigite o ID do usu�rio a ser deletado: ");
                    scanf("%d", &id);
                    deleteUsuario(id);
                }
                else if (userOption == 3) {
                    // Atualizar um usu�rio
                    int id;
                    char email[255], nome[100], senha[255];
                    printf("\nDigite o ID do usu�rio a ser atualizado: ");
                    scanf("%d", &id);
                    printf("Digite o novo e-mail: ");
                    scanf(" %254[^\n]", email);
                    printf("Digite o novo nome: ");
                    scanf(" %99[^\n]", nome);
                    printf("Digite a nova senha: ");
                    scanf(" %254[^\n]", senha);
                    updateUsuario(id, email, nome, senha);
                }
                else if (userOption == 4) {
                    // Listar usu�rios
                    listarUsuarios();
                }
                else if (userOption == 5) {
                    // Voltar ao menu principal
                    break;
                }
                else {
                    printf("Op��o inv�lida. Tente novamente.\n");
                }
            } while (userOption != 5);
        }
        else if (opcao == 2) {
            // Sair do programa
            printf("\nSaindo do sistema... At� mais!\n");
        }
        else {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}
