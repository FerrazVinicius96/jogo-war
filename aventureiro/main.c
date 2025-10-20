/*
TODO OK
- Alocação dinâmica de territórios: utilizar calloc ou malloc
para alocar memória para um vetor de struct Territorio com tamanho informado pelo usuário.


- Simulação de ataques: criar uma função void atacar(Territorio* atacante, Territorio* defensor)
que simula um ataque, utilizando números aleatórios como se fossem dados de batalha.

-Atualização de dados: o território defensor deve mudar de dono (cor do exército)
se o atacante vencer, e suas tropas devem ser atualizadas.

- Exibição pós-ataque: o sistema deve exibir os dados atualizados dos territórios após cada ataque.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_TERRITORIOS 2
#define LEN_NOME 30
#define LEN_COR 10


struct Territorio {
    char nome[LEN_NOME];
    char cor[LEN_COR];
    int tropa;
};


struct Territorio *G_TERRITORIOS = NULL;
size_t G_QTD = 0;


int menu();
int cadastrar_territorios_global(void);
void listar_territorios(void);


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main(){
    int opcao;
    bool cadastro_realizado = false;
    struct Territorio territorios[MAX_TERRITORIOS];


    do{
        opcao = menu();
        switch(opcao){
            case 1:
                if (!cadastro_realizado){
                    cadastrar_territorios_global();
                    cadastro_realizado = true;
                } else {
                    printf("\nTerritórios já cadastrados.\n");
                }
                break;
            case 2:
                if (!cadastro_realizado){
                    printf("\nNenhum território cadastrado.\n");
                } else {
                    listar_territorios();
                }
                break;
            case 3:
                // atacar();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);


}

int menu(){
    int opcao;

    printf("\n--- MENU ---\n");
    printf("01 - Cadastrar territórios\n");
    printf("02 - Listar territórios\n");
    printf("03 - Atacar território\n");
    printf("04 - Sair\n");
    printf("Digite: ");
    scanf("%d", &opcao);
    limparBuffer();

    return opcao;
}


int cadastrar_territorios_global(void){
    size_t qtd;
    printf("Insira quantidade de territorios: ");
    if (scanf("%zu", &qtd) != 1 || qtd == 0) { limparBuffer(); return 0; }
    limparBuffer();

    free(G_TERRITORIOS);
    G_TERRITORIOS = malloc(qtd * sizeof *G_TERRITORIOS);

    if(!G_TERRITORIOS) {
        G_QTD = 0;

        return 0;
    };

    G_QTD = qtd;

    for (size_t i = 0; i < G_QTD; i++){
        printf("\n --- CADASTRO DO TERRITÓRIO %zu ---\n", i + 1);

        printf("Digite o nome do território: ");
        if (fgets(G_TERRITORIOS[i].nome, LEN_NOME, stdin) == NULL) continue;
        G_TERRITORIOS[i].nome[strcspn(G_TERRITORIOS[i].nome, "\n")] = '\0'; // remove '\n'

        printf("Digite a cor do território: ");
        if (fgets(G_TERRITORIOS[i].cor, LEN_COR, stdin) == NULL) continue;
        G_TERRITORIOS[i].cor[strcspn(G_TERRITORIOS[i].cor, "\n")] = '\0'; // remove '\n'

        printf("Digite a quantidade de tropas: ");
        while (scanf("%d", &G_TERRITORIOS[i].tropa) != 1 || G_TERRITORIOS[i].tropa < 0) {
            printf("Valor inválido. Digite um número inteiro positivo: ");
            limparBuffer();
        }
        limparBuffer();
    }
    return 1;
}

void listar_territorios(void) {
    printf("\n--- LISTA DE TERRITÓRIOS ---\n");
    for (int i = 0; i < G_QTD; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", G_TERRITORIOS[i].nome);
        printf("  Cor: %s\n", G_TERRITORIOS[i].cor);
        printf("  Tropas: %d\n\n", G_TERRITORIOS[i].tropa);
    }
}