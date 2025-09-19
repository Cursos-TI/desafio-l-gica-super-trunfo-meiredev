#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char nomePais[100];         // Nome do país
    char estado[3];             // Código do estado (2 caracteres + '\0')
    char nomeCidade[100];       // Nome da cidade
    int populacao;              // População da cidade
    float area;                 // Área da cidade
    float pib;                  // PIB da cidade
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadeDemografica; // Densidade demográfica (calculada)
    float pibPerCapita;         // PIB per capita (calculado)
} Carta;

// Função para calcular a densidade demográfica e o PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para comparar o atributo escolhido entre duas cartas
void compararCartas(Carta carta1, Carta carta2, int atributoEscolhido) {
    switch (atributoEscolhido) {
        case 1: // Comparar População
            printf("Comparação de cartas (Atributo: População):\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 2: // Comparar Área
            printf("Comparação de cartas (Atributo: Área):\n");
            printf("Carta 1 - %s (%s): %.2f km²\n", carta1.nomeCidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f km²\n", carta2.nomeCidade, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 3: // Comparar PIB
            printf("Comparação de cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 4: // Comparar Número de Pontos Turísticos
            printf("Comparação de cartas (Atributo: Pontos Turísticos):\n");
            printf("Carta 1 - %s (%s): %d pontos turísticos\n", carta1.nomeCidade, carta1.estado, carta1.pontosTuristicos);
            printf("Carta 2 - %s (%s): %d pontos turísticos\n", carta2.nomeCidade, carta2.estado, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        case 5: // Comparar Densidade Demográfica
            printf("Comparação de cartas (Atributo: Densidade Demográfica):\n");
            printf("Carta 1 - %s (%s): %.2f habitantes/km²\n", carta1.nomeCidade, carta1.estado, carta1.densidadeDemografica);
            printf("Carta 2 - %s (%s): %.2f habitantes/km²\n", carta2.nomeCidade, carta2.estado, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    Carta carta1, carta2;
    int atributoEscolhido;

    // Cadastro da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Nome do país: ");
    fgets(carta1.nomePais, 100, stdin);
    carta1.nomePais[strcspn(carta1.nomePais, "\n")] = '\0'; // Remover o '\n' de fgets
    printf("Código do estado: ");
    scanf("%s", carta1.estado);
    getchar(); // Consumir o caractere de nova linha pendente
    printf("Nome da cidade: ");
    fgets(carta1.nomeCidade, 100, stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = '\0'; // Remover o '\n' de fgets
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    calcularIndicadores(&carta1);  // Calcular Densidade Demográfica e PIB per capita

    // Cadastro da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    getchar(); // Consumir o caractere de nova linha pendente
    printf("Nome do país: ");
    fgets(carta2.nomePais, 100, stdin);
    carta2.nomePais[strcspn(carta2.nomePais, "\n")] = '\0'; // Remover o '\n' de fgets
    printf("Código do estado: ");
    scanf("%s", carta2.estado);
    getchar(); // Consumir o caractere de nova linha pendente
    printf("Nome da cidade: ");
    fgets(carta2.nomeCidade, 100, stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = '\0'; // Remover o '\n' de fgets
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    calcularIndicadores(&carta2);  // Calcular Densidade Demográfica e PIB per capita

    // Menu interativo
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &atributoEscolhido);

    // Comparar as cartas com base no atributo escolhido
    compararCartas(carta1, carta2, atributoEscolhido);

    return 0;
}
