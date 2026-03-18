#include <iostream>
#include <iomanip>

using namespace std;

// Função que processa o acúmulo de cashback baseado em categorias
void calcular_cashback_total(int valores[], int categorias[], int total_itens) {
    float valor_total_cashback = 0;

    for (int i = 0; i < total_itens; i++) {
        float cashback_item = 0;

        if (categorias[i] == 0) {
            cashback_item = valores[i] * 0.05; // Categoria 0: 5%
        } else if (categorias[i] == 1) {
            cashback_item = valores[i] * 0.25; // Categoria 1: 25%
        }
        
        valor_total_cashback += cashback_item;
    }

    cout << fixed << setprecision(2);
    cout << "Cashback acumulado: R$ " << valor_total_cashback << endl;
}

int main() {
    char nome_cliente[51];
    cin.getline(nome_cliente, 51);

    int qtd_registros;
    cin >> qtd_registros;

    // Arrays para armazenar os dados de entrada
    int valores_abastecidos[qtd_registros];
    int tipos_cashback[qtd_registros];

    for (int i = 0; i < qtd_registros; i++) {
        cin >> valores_abastecidos[i];
        cin >> tipos_cashback[i];
    }

    cout << "---------------------------" << endl;
    cout << "Cliente: " << nome_cliente << endl;
    calcular_cashback_total(valores_abastecidos, tipos_cashback, qtd_registros);
    cout << "---------------------------" << endl;

    return 0;
}
