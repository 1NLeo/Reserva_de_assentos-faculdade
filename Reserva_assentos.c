#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");

    int opt;
    int sessao;
    int num_assento;
    int assentos[3][5] = { // 0 = livre e 1 = reservado.
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    float ingresso[3];

    for (int i = 0; i < 3; i++) { // For para percorrer o vetor ingresso
        printf("Digite o valor do ingresso de cada sessão: \n");

        do {
            printf("Sessão %d: ", i + 1);
            scanf("%f", &ingresso[i]);
        } while (ingresso[i] <= 0);
        
    }

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
                // "\t" Serve como tabulação, então ele deixa organizado o número dos assentos na horizontal

                printf("Legenda: 0 = livre e 1 = reservado.\n");

                printf("Assento\t\t"); printf("1\t"); printf("2\t"); printf("3\t"); printf("4\t"); printf("5\n");
                printf("--------------------------------------------------\n");

                    for (int i = 0; i < 3; i++) { 
                        printf("Sessão %d\t", i + 1);
                                                            // for dentro de outro for para conseguir percorrer o vetor
                        for (int j = 0; j < 5; j++) {
                            printf("%d\t", assentos[i][j]);
                        }
                        printf("\n");       
                    }

            break;

            case 2: // Reserva de assento
                
                    printf("Digite o número da sessão: ");
                    scanf("%d", &sessao);

                    if (sessao < 1 || sessao > 3) { // Se a sessão digitada não estiver entre 1 e 3 volta para o menu
                        printf("Sessão inválida!\n");
                        break;
                    }

                    printf("Digite o número do assento: ");
                    scanf("%d", &num_assento);

                    if (num_assento < 1 || num_assento > 5) { // Se o assento digitado não estiver entre 1 e 5 volta para o menu
                        printf("Assento inválido!\n");
                        break;
                    }

                    if (assentos[sessao - 1][num_assento - 1] == 0) { // Se o assento estiver com o numero 0 na matriz ele poderá ser reservado
                        printf("Assento reservado!\n");
                        printf("Preço do ingresso: %f\n", ingresso[sessao - 1]);

                        assentos[sessao - 1][num_assento - 1] = 1;
                    }
                    else { 
                        printf("Este assento ja foi reservado ):\n");
                    }

            break;

            case 3: // Canelamento de reserva

                printf(" |Sessão de cancelamento|\n");

                printf("Digite o número da sessão: ");
                scanf("%d", &sessao);

                printf("Digite o número do assento: ");
                scanf("%d", &num_assento);

                if(sessao > 0 && sessao < 4 && num_assento > 0 && num_assento < 6) { // condicional básica para garantir que não seja permitido
                                                                                     // um valor de sessão e assento inexistente
                    if (assentos[sessao - 1][num_assento - 1] == 1) { // sessão e assento - 1, pois o vetor começa em 0
                        printf("Cancelamento de assento confirmado!\n");
                        assentos[sessao - 1][num_assento - 1] = 0;
                    }
                    else {
                        printf("Este assento não está reservado!\n");
                    }

                }

                else {
                    printf("Número de sessão ou assento inválido!\n");
                }

            break;

            case 4: // Resumo das sessões
            
            // Variáveis criadas dentro do case apenas para validação de assentos e total de vendas
            int assentos_livres = 0; 
            int assentos_ocupados = 0;
            float total_geral = 0.0;
                
                for (int i = 0; i < 3; i++) { // for para percorrer as linhas

                    assentos_livres = 0; // Aqui a gente reseta o valor das duas variáveis relacionadas a assento  
                    assentos_ocupados = 0; // Pra garantir que não vão ser contados os assentos de outra sessão também

                    printf("Sessão %d: \n", i + 1);

                    for (int j = 0; j < 5; j++) { // for para percorrer as colunas
                        if (assentos[i][j] == 0){ // dessa forma nós conseguimos acessar os valores dentro da matriz
                            assentos_livres += 1; // Quando o assento é igual a 0 ele adiciona mais 1 em assentos_livres
                        }
                        else { // Se o assento for diferente de 0 ele adiciona mais 1 em assentos_ocupados
                            assentos_ocupados += 1;
                        }
                    }

                    printf("Assentos livres: %d\n", assentos_livres);
                    printf("Assentos ocupados: %d\n", assentos_ocupados);

                    printf("Valor total em reservas sessão %d: %.2f", i + 1, ingresso[i] * assentos_ocupados); // cálculo para descobrir o total da sessão
                    total_geral += ingresso[i] * assentos_ocupados; // Variável total_geral para adicionar ao final de cada loop o valor total da sessão

                    printf("\n");       
                }
                printf("Total geral: %f\n", total_geral);

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