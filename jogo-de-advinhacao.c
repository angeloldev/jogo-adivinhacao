#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 5

int main() {

    printf("\n\n");
    printf("          P  /_\\  P                               \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao      \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao!  \n");
    printf("    |" "  |  |_|  |"  " |                          \n");
    printf("    |_____| ' _ ' |_____|                          \n");
    printf("          \\__|_|__/                               \n");
    printf("\n\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    

    int nivel;
    printf("Escolha o nivel de dificuldade:\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;
    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;

        case 2:
            numerodetentativas = 15;
            break;
        default:
            numerodetentativas = 6;
            break;
    }

    //for(int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
    for(int i = 1; i <= numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        printf("O seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Voce nao pode digitar numeros negativos!\n");
            continue;
        }
        int maior = chute > numerosecreto;

        if(acertou) {
            break; //ganhou =1;
        }

        else if(maior) {
            printf("Seu chute foi maior que o numero secreto!\n\n");
        }

        else {
            printf("Seu chute foi menor que o numero secreto!\n\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
        
    }

    printf("Fim de jogo!\n");

    if(acertou) {
        printf("Voce ganhou!\n");
        printf("Voce acertou o numero secreto em %d tentativas! \n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }

    else {
        printf("Voce perdeu! Tente de novo.\n");
    }
}
