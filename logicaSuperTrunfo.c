#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nomePais[100];
    char estado[3];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade demográfica e PIB per capita
void calcularIndicadores(Carta *c) {
    c->densidadeDemografica = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

// Função para exibir o menu e escolher o atributo
int escolherAtributo(int atributoBloqueado) {
    int opcao;
    printf("\nEscolha um atributo para comparação:\n");
    if (atributoBloqueado != 1) printf("1 - População\n");
    if (atributoBloqueado != 2) printf("2 - Área\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (atributoBloqueado != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    // Validação da escolha
    if (opcao < 1 || opcao > 5 || opcao == atributoBloqueado) {
        printf("Opção inválida! Tente novamente.\n");
        return escolherAtributo(atributoBloqueado);
    }

    return opcao;
}

// Função para retornar o valor do atributo
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0.0f;
    }
}

// Função para obter nome do atributo
const char* nomeDoAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função principal de comparação
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    float valorC1_A = obterValorAtributo(c1, atributo1);
    float valorC2_A = obterValorAtributo(c2, atributo1);
    float valorC1_B = obterValorAtributo(c1, atributo2);
    float valorC2_B = obterValorAtributo(c2, atributo2);

    // Exibir valores dos atributos
    printf("\n--- COMPARAÇÃO DE CARTAS ---\n");
    printf("Carta 1 - %s (%s)\n", c1.nomeCidade, c1.nomePais);
    printf("Carta 2 - %s (%s)\n\n", c2.nomeCidade, c2.nomePais);

    printf("%s:\n", nomeDoAtributo(atributo1));
    printf("  %s: %.2f\n", c1.nomeCidade, valorC1_A);
    printf("  %s: %.2f\n\n", c2.nomeCidade, valorC2_A);

    printf("%s:\n", nomeDoAtributo(atributo2));
    printf("  %s: %.2f\n", c1.nomeCidade, valorC1_B);
    printf("  %s: %.2f\n\n", c2.nomeCidade, valorC2_B);

    // Inversão da lógica para densidade
    valorC1_A = (atributo1 == 5) ? -valorC1_A : valorC1_A;
    valorC2_A = (atributo1 == 5) ? -valorC2_A : valorC2_A;
    valorC1_B = (atributo2 == 5) ? -valorC1_B : valorC1_B;
    valorC2_B = (atributo2 == 5) ? -valorC2_B : valorC2_B;

    float soma1 = valorC1_A + valorC1_B;
    float soma2 = valorC2_A + valorC2_B;

    printf("Soma dos valores (após regra de comparação):\n");
    printf("  %s: %.2f\n", c1.nomeCidade, soma1);
    printf("  %s: %.2f\n", c2.nomeCidade, soma2);

    // Operador ternário para decidir o vencedor
    printf("\nResultado: ");
    soma1 == soma2
        ? printf("Empate!\n")
        : (soma1 > soma2
            ? printf("Carta 1 (%s) venceu!\n", c1.nomeCidade)
            : printf("Carta 2 (%s) venceu!\n", c2.nomeCidade));
}

int main() {
    Carta c1, c2;
    int atributo1, atributo2;

    // Entrada Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Nome do país: ");
    fgets(c1.nomePais, 100, stdin);
    c1.nomePais[strcspn(c1.nomePais, "\n")] = 0;

    printf("Código do estado: ");
    scanf("%s", c1.estado);
    getchar();

    printf("Nome da cidade: ");
    fgets(c1.nomeCidade, 100, stdin);
    c1.nomeCidade[strcspn(c1.nomeCidade, "\n")] = 0;

    printf("População: ");
    scanf("%d", &c1.populacao);
    printf("Área: ");
    scanf("%f", &c1.area);
    printf("PIB: ");
    scanf("%f", &c1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &c1.pontosTuristicos);

    calcularIndicadores(&c1);

    // Entrada Carta 2
    getchar();
    printf("\nCadastro da Carta 2:\n");
    printf("Nome do país: ");
    fgets(c2.nomePais, 100, stdin);
    c2.nomePais[strcspn(c2.nomePais, "\n")] = 0;

    printf("Código do estado: ");
    scanf("%s", c2.estado);
    getchar();

    printf("Nome da cidade: ");
    fgets(c2.nomeCidade, 100, stdin);
    c2.nomeCidade[strcspn(c2.nomeCidade, "\n")] = 0;

    printf("População: ");
    scanf("%d", &c2.populacao);
    printf("Área: ");
    scanf("%f", &c2.area);
    printf("PIB: ");
    scanf("%f", &c2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &c2.pontosTuristicos);

    calcularIndicadores(&c2);

    // Escolha de atributos
    atributo1 = escolherAtributo(0); // Sem bloqueio na primeira escolha
    atributo2 = escolherAtributo(atributo1); // Bloqueia o primeiro escolhido

    // Comparação
    compararCartas(c1, c2, atributo1, atributo2);

    return 0;
}
