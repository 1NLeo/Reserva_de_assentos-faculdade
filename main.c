#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int opt;
    int assentos[3][5] = { // 0 = livre e 1 = reservado.
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    do {

        printf ("================================\n");
        printf ("|             MENU             |\n" );
        printf ("================================\n");
        printf ("|1- Mostrar mapa de assentos   |\n");
        printf ("|2- Reservar assento           |\n");
        printf ("|3- Cancelar reserva           |\n");
        printf ("|4- Mostrar resumo das sessões |\n");
        printf ("|0- Sair                       |\n");
        printf ("|==============================|\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opt);
        printf("\n");

        switch (opt) {
            case 1: // Mapa de assentos

            printf("Assento\t\t"); printf("1\t"); printf("2\t"); printf("3\t"); printf("4\t"); printf("5\n");
            printf("--------------------------------------------------\n");

                for (int i = 0; i < 3; i++) {
                    printf("Sessão %d\t", i);

                    for (int j = 0; j < 5; j++) {
                        printf("%d\t", assentos[i][j]);
                    }
                    printf("\n");       
                }

            break;

            case 2:
            
            break;

            case 3:
            
            break;

            case 4:
            
            break;

            case 0:
            printf("Saindo...\n");
            break;   
            
            default:
            printf("ERRO: Opção inválida!\n"); printf("Digite uma opção válida: ");
            break;
        }

    } while (opt != 0);


    return 0;
}