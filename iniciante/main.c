#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 2
#define LEN_NOME 30
#define LEN_COR 10

struct Territorio {
    char nome[LEN_NOME];
    char cor[LEN_COR];
    int tropa;
};

int menu();
void cadastrar_territorio(struct Territorio territorios[]);
void listar_territorios(struct Territorio territorios[]);


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    int opcao;
    struct Territorio territorios[MAX_TERRITORIOS];



    do{
        opcao = menu();
        switch(opcao){
            case 1:
                cadastrar_territorio(territorios);
                break;
            case 2:
                listar_territorios(territorios);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 3);


}

int menu(){
    int opcao;

    printf("\n--- MENU ---\n");
    printf("01 - Cadastrar territórios\n");
    printf("02 - Listar territórios\n");
    printf("03 - Sair\n");
    printf("Digite: ");
    scanf("%d", &opcao);
    limparBuffer();

    return opcao;
}


void cadastrar_territorio(struct Territorio territorios[]) {
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Digite o nome do território: ");
        if (fgets(territorios[i].nome, LEN_NOME, stdin) == NULL) continue;
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // remove '\n'

        printf("Digite a cor do território: ");
        if (fgets(territorios[i].cor, LEN_COR, stdin) == NULL) continue;
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0'; // remove '\n'

        printf("Digite a quantidade de tropas: ");
        while (scanf("%d", &territorios[i].tropa) != 1 || territorios[i].tropa < 0) {
            printf("Valor inválido. Digite um número inteiro positivo: ");
            limparBuffer();
        }
        limparBuffer();
    }

    listar_territorios(territorios);
}

void listar_territorios(struct Territorio territorios[]) {
    printf("\n--- LISTA DE TERRITÓRIOS ---\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n\n", territorios[i].tropa);
    }
}