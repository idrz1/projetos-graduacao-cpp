#include <iostream>

using namespace std;

// Função que altera o "case" das letras baseando-se na contagem de espaços (palavras)
void transformar_texto(char str[]) {
    int cont_palavras = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            cont_palavras++;
        }

        if (cont_palavras % 2 != 0) { // Palavras ímpares: Maiúsculas
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 'a' + 'A';
            }
        } 
        else { // Palavras pares: Minúsculas
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }
        }
    }
}

int main() {
    char str[100];
    
    // Lê a frase completa incluindo espaços
    cin.getline(str, 100);

    transformar_texto(str);

    cout << str << endl;

    return 0;
}
