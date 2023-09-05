#include <stdio.h>

int main() {
    int numPerguntas;

    printf("Quantas perguntas deseja na prova? ");
    scanf("%d", &numPerguntas);

    if (numPerguntas <= 0 || numPerguntas > 100) {
        printf("Número de perguntas inválido. Use um valor entre 1 e 100.\n");
        return 1;
    }

    FILE *provaFile = fopen("prova.txt", "w");

    if (provaFile == NULL) {
        printf("Erro ao criar o arquivo da prova.\n");
        return 1;
    }

    for (int i = 1; i <= numPerguntas; i++) {
        char pergunta[256];
        char resposta[256];

        printf("\nPergunta %d:\n", i);
        printf("Digite a pergunta: ");
        scanf(" %[^\n]%*c", pergunta);
        printf("Digite a resposta: ");
        scanf(" %[^\n]%*c", resposta);

        fprintf(provaFile, "Pergunta %d: %s\n", i, pergunta);
        fprintf(provaFile, "Resposta %d: %s\n", i, resposta);
    }

    fclose(provaFile);

    printf("\nProva criada com sucesso. Consulte o arquivo 'prova.txt'.\n");

    return 0;
}
