#include <stdio.h>
#include <stdlib.h>

/* Protótipo da função */
int calcular_custo_beneficio(float preco_gas, float preco_eta);

int main() {
    float preco_gasolina, preco_etanol;

    printf("######## MEDIDOR DA PETROBRAS ######## by:drz\n\n");

    printf("Digite o valor da Gasolina:\n");
    scanf("%f", &preco_gasolina);

    printf("Digite o valor da Etanol:\n");
    scanf("%f", &preco_etanol);

    int resultado = calcular_custo_beneficio(preco_gasolina, preco_etanol);

    if (resultado == 0) {
        printf("\nCompensa abastecer com GASOLINA.\n\n");
    } 
    else if (resultado == 1) {
        printf("\nCompensa abastecer com ETANOL.\n\n");
    } 
    else {
        printf("\nTanto faz, etanol ou gasolina.\n\n");
    }

    system("pause");
    return 0;
}

/* Função que aplica a regra de 70% para eficiência */
int calcular_custo_beneficio(float v_gas, float v_eta) {
    float limite_etanol = v_gas * 0.7;

    if (limite_etanol < v_eta) {
        return 0; // Gasolina vence
    } 
    else if (limite_etanol > v_eta) {
        return 1; // Etanol vence
    } 
    else {
        return 2; // Empate técnico
    }
}
