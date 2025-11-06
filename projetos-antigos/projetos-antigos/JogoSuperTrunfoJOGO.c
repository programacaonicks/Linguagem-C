#include <stdio.h>

// Definição da estrutura para armazenar os dados da cidade
typedef struct {
    char nomeCidade[50];
    char nomeEstado[50];
    int codigo;
    int codigoEstado;
    int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
    double superPoder;
} Carta;

// Função para calcular os valores derivados
void calcularValores(Carta *c) {
    if (c->area > 0) {
        c->densidadePopulacional = c->populacao / c->area;
    } else {
        c->densidadePopulacional = 0;
    }
    if (c->populacao > 0) {
        c->pibPerCapita = (c->pib * 1e9) / c->populacao;
    } else {
        c->pibPerCapita = 0;
    }
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos;
}

// Função para exibir a lista de cidades disponíveis
void exibirListaCidades(Carta cidades[], int numCidades) {
    printf("Lista de cidades disponíveis:\n");
    for (int i = 0; i < numCidades; i++) {
        printf("%d - %s (%s)\n", i, cidades[i].nomeCidade, cidades[i].nomeEstado);
    }
}

// Função para exibir os dados da cidade
void exibirCarta(Carta c) {
    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", c.nomeCidade);
    printf("Estado: %s\n", c.nomeEstado);
    printf("Código da cidade: %d\n", c.codigo);
    printf("Código do estado: %d\n", c.codigoEstado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", c.pibPerCapita);
}

// Função para comparar os atributos escolhidos pelo usuário
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\n=== Comparação entre %s e %s ===\n", c1.nomeCidade, c2.nomeCidade);
    
    double valor1, valor2;
    char *nomeAtributo;
    int inverso = 0; // 1 se o menor valor for o vencedor (para densidade demográfica)

    switch (atributo) {
        case 1: nomeAtributo = "População"; valor1 = c1.populacao; valor2 = c2.populacao; break;
        case 2: nomeAtributo = "Área (km²)"; valor1 = c1.area; valor2 = c2.area; break;
        case 3: nomeAtributo = "PIB (bilhões)"; valor1 = c1.pib; valor2 = c2.pib; break;
        case 4: nomeAtributo = "Pontos Turísticos"; valor1 = c1.pontosTuristicos; valor2 = c2.pontosTuristicos; break;
        case 5: 
            nomeAtributo = "Densidade Populacional";
            valor1 = c1.densidadePopulacional;
            valor2 = c2.densidadePopulacional;
            inverso = 1; // Aqui a menor densidade vence
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("%-25s | %-15.2f | %-15.2f\n", nomeAtributo, valor1, valor2);

    if (valor1 == valor2) {
        printf("\nEmpate!\n");
    } else if ((valor1 > valor2 && !inverso) || (valor1 < valor2 && inverso)) {
        printf("\n%s venceu!\n", c1.nomeCidade);
    } else {
        printf("\n%s venceu!\n", c2.nomeCidade);
    }
}
// Função para exibir os atributos disponíveis
void exibirAtributos() {
    printf("\nAtributos disponíveis para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (bilhões)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
}

// Função para obter o valor de um atributo específico
double obterAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        default: return -1;
    }
}

// Função para comparar dois atributos (Modo Aventureiro)
void compararCartasAventureiro(Carta c1, Carta c2, int atributo) {
    printf("\n=== Comparação entre %s e %s ===\n", c1.nomeCidade, c2.nomeCidade);
    
    double valor1 = obterAtributo(c1, atributo);
    double valor2 = obterAtributo(c2, atributo);
    int inverso = (atributo == 5); // Densidade: menor valor vence

    if (valor1 == valor2) {
        printf("\nEmpate!\n");
    } else if ((valor1 > valor2 && !inverso) || (valor1 < valor2 && inverso)) {
        printf("\nVencedor: %s\n", c1.nomeCidade);
    } else {
        printf("\nVencedor: %s\n", c2.nomeCidade);
    }
}

// Função para comparar dois atributos no Modo Mestre
void compararCartasMestre(Carta c1, Carta c2, int atributo1, int atributo2) {
    int pontosC1 = 0, pontosC2 = 0;
    
    double valor1_c1 = obterAtributo(c1, atributo1);
    double valor1_c2 = obterAtributo(c2, atributo1);
    double valor2_c1 = obterAtributo(c1, atributo2);
    double valor2_c2 = obterAtributo(c2, atributo2);

    int inverso1 = (atributo1 == 5); // Densidade: menor valor vence
    int inverso2 = (atributo2 == 5);

    printf("\n=== Comparação Modo Mestre ===\n");
    printf("%s vs %s\n", c1.nomeCidade, c2.nomeCidade);

    // Comparação do primeiro atributo
    if (valor1_c1 == valor1_c2) {
        printf("Atributo 1: Empate\n");
    } else if ((valor1_c1 > valor1_c2 && !inverso1) || (valor1_c1 < valor1_c2 && inverso1)) {
        printf("Atributo 1: %s venceu\n", c1.nomeCidade);
        pontosC1++;
    } else {
        printf("Atributo 1: %s venceu\n", c2.nomeCidade);
        pontosC2++;
    }

    // Comparação do segundo atributo
    if (valor2_c1 == valor2_c2) {
        printf("Atributo 2: Empate\n");
    } else if ((valor2_c1 > valor2_c2 && !inverso2) || (valor2_c1 < valor2_c2 && inverso2)) {
        printf("Atributo 2: %s venceu\n", c1.nomeCidade);
        pontosC1++;
    } else {
        printf("Atributo 2: %s venceu\n", c2.nomeCidade);
        pontosC2++;
    }

    // Determinar vencedor final
    if (pontosC1 > pontosC2) {
        printf("\nVencedor final: %s\n", c1.nomeCidade);
    } else if (pontosC1 < pontosC2) {
        printf("\nVencedor final: %s\n", c2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }
}
    int main() {

    // Array contendo as 32 cidades
    Carta cidades[32] = {
        {"Jundiaí", "São Paulo", 352000, 1, 425000, 431.4, 21.0, 12, 0, 0, 0},
        {"Ribeirao Preto", "São Paulo", 3543452, 1, 700000, 651.23, 28, 14, 0, 0},
        {"Sorocaba", "São Paulo", 3552205, 1, 700000, 45.6, 22, 12, 0, 0, 0},
        {"Osasco", "São Paulo", 3534401, 1, 700000, 65.35, 25, 10, 0, 0, 0},
        {"Cabo Frio", "Rio de Janeiro", 3300703, 2, 240000, 402.41, 6.5, 15, 0, 0, 0},
        {"Niteroi", "Rio de Janeiro", 3303302, 2, 520000, 133.56, 26, 15, 0, 0, 0},
        {"Angra dos Reis", "Rio de Janeiro", 3300100, 2, 200000, 826.8, 8.5, 20, 0, 0, 0},
        {"Itaguai", "Rio de Janeiro", 3302001, 2, 130000, 434.8, 4, 10, 0, 0, 0},
        {"Belo Horizonte", "Minas Gerais", 3106200, 3, 25000, 331.4, 85, 20, 0, 0, 0},
        {"Ipatinga", "Minas Gerais", 3131306, 3, 270000, 146.3, 6, 10, 0, 0, 0},
        {"Betim", "Minas Gerais", 3106808, 3, 45000, 69.6, 4, 10, 0, 0,0},
        {"Divinopolis", "Minas Gerais", 3122306, 3, 25000, 225.8, 4.5, 10, 0, 0, 0},
        {"Belo Horizonte", "Minas Gerais", 3106200, 3, 25000, 331.4, 85, 20, 0, 0, 0},
        {"Salvador", "Bahia", 2927408, 4, 29000, 693.8, 88, 35, 0, 0, 0},
        {"Porto Seguro", "Bahia", 29271088, 4, 16000, 2215.5, 3.5, 18, 0, 0, 0},
        {"Barreiras", "Bahia", 2903205, 4, 16000, 12438.4, 8.9, 8, 0, 0, 0},
        {"Alagoinha", "Bahia", 2600201, 4, 15000, 308.8, 120, 5, 0, 0, 0},
        {"Porto Alegre", "Rio Grande do Sul", 4314902, 5, 15000, 496.8, 67, 30, 0, 0, 0},
        {"Gravatai", "Rio Grande do Sul", 4309209, 5, 20000, 468.92, 6.8, 8, 0, 0, 0},
        {"Pelotas", "Rio Grande do Sul", 4313902, 5, 35000, 1492.8, 9, 12, 0, 0, 0},
        {"Caxias do Sul", "Rio Grande do Sul", 4305108, 5, 50000, 1267.8, 19, 20, 0, 0, 0},
        {"Vitoria", "Espirito Santo", 3205309, 6, 365000, 93.4, 14, 20, 0, 0, 0},
        {"Colatina", "Espirito Santo", 3202306, 6, 130000, 1345, 4, 7, 0, 0, 0},
        {"Linhares", "Espirito Santo", 3203502, 6, 17000, 4019.7, 5, 7, 0, 0, 0},
        {"Vila Velha", "Espirito Santo", 3205200, 6, 50000, 209.7, 8, 20, 0, 0, 0},
        {"Goiania", "Goias", 5208707, 7, 15000, 739.5, 32, 25, 0, 0, 0},
        {"Formosa", "Goias", 520506, 7, 120000, 5563.3,1.8, 7, 0, 0, 0},
        {"Jatai", "Goias", 5212405, 7, 110000, 10679.6, 2.6, 7, 0, 0, 0},
        {"Rio Verde", "Goias", 5218800, 7, 240000, 6153.3, 5.5, 8, 0, 0, 0},
        {"Maceio", "Alagoas", 2704302, 8, 1000000,511.0, 19, 25, 0, 0, 0},
        {"Penedo", "Alagoas", 2706301, 8, 65000, 292.0, 1.2, 8, 0, 0, 0},
        {"Arapiraca", "Alagoas", 2700300, 8, 2300000,645.2, 2.6, 7, 0, 0, 0},
        {"Maragogi", "ALagoas", 2706102, 8, 35000, 380.0, 480, 12, 0, 0, 0},

    };

    int numCidades = 32;
    for (int i = 0; i < numCidades; i++) {
        calcularValores(&cidades[i]);
    }

    int modo, escolha1, escolha2, atributo1, atributo2;

    printf("Escolha o modo de jogo:\n1 - Modo Aventureiro (1 atributo)\n2 - Modo Mestre (2 atributos)\n");
    scanf("%d", &modo);

    exibirListaCidades(cidades, numCidades);
    printf("\nEscolha duas cidades para comparar (números): ");
    scanf("%d %d", &escolha1, &escolha2);

    if (escolha1 < 0 || escolha1 >= numCidades || escolha2 < 0 || escolha2 >= numCidades) {
        printf("\nErro: Cidades inválidas!\n");
        return 1;
    }

    exibirAtributos();
    printf("\nEscolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    if (modo == 1) {
        compararCartasAventureiro(cidades[escolha1], cidades[escolha2], atributo1);
    } else {
        do {
            printf("Escolha o segundo atributo: ");
            scanf("%d", &atributo2);
        } while (atributo1 == atributo2);
        
        compararCartasMestre(cidades[escolha1], cidades[escolha2], atributo1, atributo2);
    }
    return 0;
}
