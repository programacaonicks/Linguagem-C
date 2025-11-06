#include <stdio.h>

int main() {
    printf("Desafio Super Trunfo em C\n");

    // informações sobre as cartas
    printf("Super Trunfo: Países\n");
    printf("Número de Estados: 8\n");
    printf("Número de cidades: 32\n");

    // informações sobre os dados das cartas
    int codigo, populacao;
    int pontos_turisticos;
    float area, pib, densidadePopulacional, pibPerCapita;
    char nome[100];
    
    // carta Jundiai - Sao Paulo
    codigo = 352000;
    populacao = 425000;
    area = 431.4;
    pib = 21.0;
    pontos_turisticos = 12;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado01[] = "Sao Paulo";
    char nomeCidade[] = "Jundiai";
    char codigoEstado1 = 01;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado:%d\n", codigoEstado1);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n", pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);

    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    // carta Ribeirão Preto - Sao Paulo
    codigo = 3543402;
    populacao = 700000;
    area = 651.23;
    pib = 28;
    pontos_turisticos = 14;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade2[] = "Ribeirao Preto";
    char codigoEstado2 = 01;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade2);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado2);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Sorocaba - Sao Paulo
    codigo = 3552205;
    populacao = 700.000;
    area = 45.6;
    pib = 22;
    pontos_turisticos = 12;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade3[] = "Sorocaba";
    char codigoEstado3 = 01;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade3);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado3);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Osasco - Sao Paulo
    codigo = 3534401;
    populacao = 700.000;
    area = 65.35;
    pib = 25;
    pontos_turisticos = 10;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade4[] = "Osasco";
    char codigoEstado4 = 01;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade4);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado4);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Cabo Frio - Rio de Janeiro
    codigo = 3300703;
    populacao = 240000;
    area = 402.41;
    pib = 6.5;
    pontos_turisticos = 15;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado2[] = "Rio de Janeiro";
    char nomeCidade5[] = "Cabo Frio";
    char codigoEstado5 = 02;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade5);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado5);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Niteroi - Rio de Janeiro
    codigo = 3303302;
    populacao = 520.000;
    area = 133.56;
    pib = 25;
    pontos_turisticos = 15;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade6[] = "Niteroi";
    char codigoEstado6 = 02;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade6);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado6);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Andra dos Reis - Rio de Janeiro
    codigo = 3300100;
    populacao = 200000;
    area = 826.8;
    pib = 8.5;
    pontos_turisticos = 20;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade7[] = "Angra dos Reis";
    char codigoEstado7 = 02;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade7);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado7);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Itaguai - Rio de Janeiro
    codigo = 3302001;
    populacao = 130000;
    area = 1214.8;
    pib = 4;
    pontos_turisticos = 10;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade8[] = "Itaguai";
    char codigoEstado8 = 02;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade8);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado8);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Belo Horizonte - Minas Gerais
    codigo = 3106200;
    populacao = 2.5;
    area = 331.4;
    pib = 85;
    pontos_turisticos = 20;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado03[] = "Minas Gerais";
    char nomeCidade9[] = "Belo Horizonte";
    char codigoEstado9 = 03;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade9);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado9);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Ipatinga - Minas Gerais
    codigo = 3131306;
    populacao = 270000;
    area = 146.3;
    pib = 6;
    pontos_turisticos = 10;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade10[] = "Ipatinga";
    char codigoEstado10 = 03;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade10);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado10);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Betim - Minas Gerais
    codigo = 3106808;
    populacao = 450000;
    area = 69.6;
    pib = 4;
    pontos_turisticos = 10;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade11[] = "Betim";
    char codigoEstado11 = 03;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade11);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado11);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Divinopolis - Minas Gerais
    codigo = 3122306;
    populacao = 250000;
    area = 225.8;
    pib = 4.5;
    pontos_turisticos = 10;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade12[] = "Divinopolis";
    char codigoEstado12 = 03;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade12);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado12);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Salvador - Bahia
    codigo = 2927408;
    populacao = 2.9;
    area = 693.8;
    pib = 88;
    pontos_turisticos = 35;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado4[] = "Bahia";
    char nomeCidade13[] = "Salvador";
    char codigoEstado13 = 04;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade13);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado13);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Porto Seguro - Bahia
    codigo = 2927108;
    populacao = 160000;
    area = 2215.5;
    pib = 3.5;
    pontos_turisticos = 18;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade14[] = "Porto Seguro";
    char codigoEstado14 = 04;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade14);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado14);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Barreiras - Bahia
    codigo = 2903205;
    populacao = 160000;
    area = 12438.4;
    pib = 8.9;
    pontos_turisticos = 8;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade15[] = "Barreiras";
    char codigoEstado15 = 04;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade15);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado15);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);


    //carta Alagoinha - Bahia
    codigo = 2600201;
    populacao = 15000;
    area = 308.8;
    pib = 120;
    pontos_turisticos = 5;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade16[] = "Alagoinha";
    char codigoEstado16 = 04;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade16);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado16);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Porto Alegre - Rio Grande do Sul
    codigo = 4314902;
    populacao = 1.5;
    area = 496.8;
    pib = 67;
    pontos_turisticos = 30;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado5[] = "Rio Grande do Sul";
    char nomeCidade17[] = "Porto Alegre";
    char codigoEstado17 = 05;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade17);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado17);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Gravatai - Rio Grande do Sul
    codigo = 4309209;
    populacao = 200000;
    area = 468.92;
    pib = 6.8;
    pontos_turisticos = 8;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade18[] = "Gravatai";
    char codigoEstado18 = 05;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade18);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado18);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Pelotas - Rio Grande do Sul
    codigo = 4313902;
    populacao = 350000;
    area = 1492;
    pib = 8.9;
    pontos_turisticos = 12;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade19[] = "Pelotas";
    char codigoEstado19 = 05;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade19);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado19);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Caxias do Sul - Rio Grande do Sul
    codigo = 4305108;
    populacao = 500000;
    area = 1267.8;
    pib = 19;
    pontos_turisticos = 20;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade20[] = "Caxias do Sul";
    char codigoEstado20 = 05;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade20);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado20);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Vitoria - Espirito Santo
    codigo = 3205309;
    populacao = 365000;
    area = 93.4;
    pib = 14;
    pontos_turisticos = 20;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado6[] = "Espirito Santo";
    char nomeCidade21[] = "Vitoria";
    int codigoEstado21 = 06;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade21);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado21);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Colatina - Espirito Santo
    codigo = 3202306;
    populacao = 130000;
    area = 1345;
    pib = 4;
    pontos_turisticos = 7;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade22[] = "Colatina";
    int codigoEstado22 = 06;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade22);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado22);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Linhares - Espirito Santo
    codigo = 3203502;
    populacao = 170000;
    area = 4019.7;
    pib = 5;
    pontos_turisticos = 7;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade23[] = "Linhares";
    int codigoEstado23 = 06;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade23);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado23);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Vila Velha - Espirito Santo
    codigo = 3205200;
    populacao = 500000;
    area = 209.7;
    pib = 8;
    pontos_turisticos = 20;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade24[] = "Vila Velha";
    int codigoEstado24 = 06;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade24);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado24);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);


    //carta Goiania - Goias
    codigo = 5208707;
    populacao = 1.5;
    area = 739.5;
    pib = 32;
    pontos_turisticos = 25;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado7[] = "Goias";
    char nomeCidade25[] = "Goiania";
    int codigoEstado25 = 07;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade25);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado25);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Formosa - Goias
    codigo = 520506;
    populacao = 120000;
    area = 5563.3;
    pib = 1.8;
    pontos_turisticos = 7;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade26[] = "Formosa";
    int codigoEstado26 = 07;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade26);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado26);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Jatai - Goias
    codigo = 5212405;
    populacao = 110000;
    area = 10679.6;
    pib = 2.6;
    pontos_turisticos = 7;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade27[] = "Jatai";
    int codigoEstado27 = 07;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade27);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado27);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Rio Verde - Goias
    codigo = 5218800;
    populacao = 240000;
    area = 6153.3;
    pib = 5.5;
    pontos_turisticos = 8;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade28[] = "Rio Verde";
    int codigoEstado28 = 07;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade28);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado28);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Maceio - Alagoas
    codigo = 2704302;
    populacao = 1000000;
    area = 511.0;
    pib = 19;
    pontos_turisticos = 25;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeEstado8[] = "Alagoas";
    char nomeCidade29[] = "Maceio";
    int codigoEstado29 = 8;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade29);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado29);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Penedo - Alagoas
    codigo = 2706301;
    populacao = 65000;
    area = 292.0;
    pib = 1.2;
    pontos_turisticos = 8;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade30[] = "Penedo";
    int codigoEstado30 = 8;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade30);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado30);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Arapiraca - Alagoas
    codigo = 2700300;
    populacao = 230000;
    area = 645.2;
    pib = 2.6;
    pontos_turisticos = 7;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade31[] = "Arapiraca";
    int codigoEstado31 = 8;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade31);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado31);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    //carta Maragogi - Alagoas
    codigo = 2706102;
    populacao = 35000;
    area = 380.0;
    pib = 480;
    pontos_turisticos = 12;
    densidadePopulacional = populacao / area;
    pibPerCapita = (pib * 1000000000) / populacao;

    char nomeCidade32[] = "Maragogi";
    int codigoEstado32 = 8;

    printf("\nCadastro da Cidade:\n");
    printf("Cidade: %s\n", nomeCidade32);
    printf("Codigo da cidade: %d\n", codigo);
    printf("estado: %d\n", codigoEstado32);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("pib: %.2f bilhoes\n",pib);
    printf("Pontos turisticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita);

    return 0;
}
