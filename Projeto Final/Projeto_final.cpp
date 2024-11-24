#include <stdio.h>
#include <locale.h>
#include <string.h>

// Limite máximo de usuários
#define MAX_USERS 100

// Definição da estrutura do Usuário
struct Usuario {
    int id;
    char email[255];
    char nome[100];
    char senha[255];
};

// Array para armazenar os usuários e o contador
struct Usuario usuarios[MAX_USERS];
int usuarioCount = 0;

// Função para salvar os usuários no arquivo CSV
void salvarUsuariosCSV() {
    FILE *arquivo = fopen("usuarios.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os usuários!\n");
        return;
    }

    fprintf(arquivo, "ID,Email,Nome,Senha\n");
    for (int i = 0; i < usuarioCount; i++) {
        fprintf(arquivo, "%d,%s,%s,%s\n", usuarios[i].id, usuarios[i].email, usuarios[i].nome, usuarios[i].senha);
    }

    fclose(arquivo);
    printf("Usuários salvos em 'usuarios.csv'.\n");
}

// Função para carregar os usuários do arquivo CSV
void carregarUsuariosCSV() {
    FILE *arquivo = fopen("usuarios.csv", "r");

    if (arquivo == NULL) {
        printf("Nenhum arquivo encontrado, começando com zero usuários.\n");
        return;
    }

    char linha[500];
    fgets(linha, sizeof(linha), arquivo);

    while (fscanf(arquivo, "%d,%254[^,],%99[^,],%254[^\n]\n", &usuarios[usuarioCount].id, usuarios[usuarioCount].email, usuarios[usuarioCount].nome, usuarios[usuarioCount].senha) == 4) {
        usuarioCount++;
    }

    fclose(arquivo);
    printf("Usuários carregados de 'usuarios.csv'.\n");
}

// Função para criar um novo usuário
void createUsuario(int id, const char* email, const char* nome, const char* senha) {
    if (usuarioCount >= MAX_USERS) {
        printf("Erro: Limite de usuários atingido.\n");
        return;
    }

    struct Usuario usuario;
    usuario.id = id;
    strcpy(usuario.email, email);
    strcpy(usuario.nome, nome);
    strcpy(usuario.senha, senha);
    usuarios[usuarioCount++] = usuario;
    printf("\nUsuário criado com sucesso!\n");
    salvarUsuariosCSV();
}

// Função para ler um usuário por ID
struct Usuario* readUsuario(int id) {
    for (int i = 0; i < usuarioCount; i++) {
        if (usuarios[i].id == id) {
            return &usuarios[i];
        }
    }
    return NULL;
}

// Função para atualizar um Usuário
void updateUsuario(int id, const char* email, const char* nome, const char* senha) {
    struct Usuario* usuario = readUsuario(id);
    if (usuario != NULL) {
        strcpy(usuario->email, email);
        strcpy(usuario->nome, nome);
        strcpy(usuario->senha, senha);
        printf("\nUsuário atualizado com sucesso!\n");
        salvarUsuariosCSV();
    } else {
        printf("\nUsuário não encontrado.\n");
    }
}

// Função para deletar um usuário
void deleteUsuario(int id) {
    struct Usuario* usuario = readUsuario(id);
    if (usuario == NULL) {
        printf("\nUsuário não encontrado.\n");
        return;
    }
    int usuarioIndex = usuario - usuarios;

    for (int i = usuarioIndex; i < usuarioCount - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }
    usuarioCount--;
    printf("\nUsuário deletado com sucesso!\n");
    salvarUsuariosCSV();
}
// Função para listar todos os usuários
void listarUsuarios() {
    if (usuarioCount == 0) {
        printf("\nNenhum usuário cadastrado.\n");
        return;
    }
    printf("\nUsuários cadastrados:\n");
    for (int i = 0; i < usuarioCount; i++) {
        printf("ID: %d, Email: %s, Nome: %s, Senha: %s\n", usuarios[i].id, usuarios[i].email, usuarios[i].nome, usuarios[i].senha);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    carregarUsuariosCSV();

    do {
        // Menu de opções
        printf("\n==============================================\n");
        printf("     SISTEMA DE GERENCIAMENTO DE USUÁRIOS\n");
        printf("==============================================\n");
        printf("1. Gerenciar Usuários\n");
        printf("2. Sair\n");
        printf("----------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Menu de gerenciamento de usuários
            int userOption;
            do {
                printf("\n1. Adicionar Usuário\n");
                printf("2. Deletar Usuário\n");
                printf("3. Atualizar Usuário\n");
                printf("4. Listar Usuários\n");
                printf("5. Voltar ao Menu Principal\n");
                printf("Escolha uma opção: ");
                scanf("%d", &userOption);

                if (userOption == 1) {
                    // Adicionar um novo usuário
                    int id;
                    char email[255], nome[100], senha[255];
                    printf("\nDigite o ID do novo usuário: ");
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
                    // Deletar um usuário
                    int id;
                    printf("\nDigite o ID do usuário a ser deletado: ");
                    scanf("%d", &id);
                    deleteUsuario(id);
                }
                else if (userOption == 3) {
                    // Atualizar um usuário
                    int id;
                    char email[255], nome[100], senha[255];
                    printf("\nDigite o ID do usuário a ser atualizado: ");
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
                    // Listar usuários
                    listarUsuarios();
                }
                else if (userOption == 5) {
                    // Voltar ao menu principal
                    break;
                }
                else {
                    printf("Opção inválida. Tente novamente.\n");
                }
            } while (userOption != 5);
        }
        else if (opcao == 2) {
            // Sair do programa
            printf("\nSaindo do sistema... Até mais!\n");
        }
        else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}
