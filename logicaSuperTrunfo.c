#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados
typedef struct {
    char estado[3];            // Código do estado (2 caracteres + '\0')
    char nomeCidade[100];      // Nome da cidade
    int populacao;             // População da cidade
    float area;                // Área da cidade
    float pib;                 // PIB da cidade
    int pontosTuristicos;      // Número de pontos turísticos
    float densidadePopulacional;  // Densidade populacional (calculada)
    float pibPerCapita;        // PIB per capita (calculado)
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para comparar o atributo escolhido entre duas cartas
void compararCartas(Carta carta1, Carta carta2) {
    // Atributo escolhido para a comparação
    const char* atributo = "População";  // Atributo a ser comparado (pode ser modificado)
    
    // Comparando o atributo População
    if (strcmp(atributo, "População") == 0) {
        printf("Comparação de cartas (Atributo: População):\n");
        printf("Carta 1 - %s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
        
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate! As duas cartas têm a mesma população.\n");
        }
    }
    // Adicionar outras comparações aqui para "Área", "PIB", "Densidade Populacional", ou "PIB per capita"
}

int main() {
    // Criando as duas cartas
    Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Nome da cidade: ");
    getchar(); // Consumir o caractere de nova linha pendente
    fgets(carta1.nomeCidade, 100, stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = '\0';  // Remover o '\n' de fgets
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    calcularIndicadores(&carta1);  // Calcular Densidade Populacional e PIB per capita

    // Cadastro da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Nome da cidade: ");
    getchar();  // Consumir o caractere de nova linha pendente
    fgets(carta2.nomeCidade, 100, stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = '\0';  // Remover o '\n' de fgets
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    calcularIndicadores(&carta2);  // Calcular Densidade Populacional e PIB per capita

    // Menu interativo
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &atributoEscolhido);

    // Comparar as duas cartas
    compararCartas(carta1, carta2);
    
    return 0;

}
