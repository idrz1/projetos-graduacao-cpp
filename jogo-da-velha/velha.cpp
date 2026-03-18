#include <iostream>

using namespace std;

void Tabuleiro(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9){
    cout <<"   |   |   " << endl;
    cout <<" " << p1 << " | "<< p2 << " | " << p3 << " " << endl;
    cout <<"---|---|---" << endl;
    cout <<" " << p4 << " | "<< p5 << " | " << p6 << " " << endl;
    cout <<"---|---|---" << endl;
    cout <<" " << p7 << " | "<< p8 << " | " << p9 << " " << endl;
    cout <<"   |   |   " << endl;

}

bool vitoria(char simbolo, char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9){
    if(p1==simbolo && p2==simbolo && p3==simbolo || 
       p4==simbolo && p5==simbolo && p6==simbolo || 
       p7==simbolo && p8==simbolo && p9==simbolo) {

        return true;
    }
    if(p1==simbolo && p4==simbolo && p7==simbolo || 
       p2==simbolo && p5==simbolo && p8==simbolo || 
       p3==simbolo && p6==simbolo && p9==simbolo) {
        
        return true;
    }
    if(p1==simbolo && p5==simbolo && p9==simbolo || 
       p7==simbolo && p5==simbolo && p3==simbolo ) {
        
        return true;

    } else 

        return false;

}

bool empate(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9){
    if(p1!='1' && p2!='2' && p3!='3' &&
       p4!='4' && p5!='5' && p6!='6' &&
       p7!='7' && p8!='8' && p9!='9'){

        return true;

       } else 

        return false;

}

int main(){

char simboloJG1, simboloJG2;

cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
cout << "|| BOAS VINDAS AO JOGO DA VELHA DA UFJF!!! ||\n";
cout << "||||||||||||||||||||||||||||||||||||||||||||| feito por : Eduardo Loschi, Arthur Miranda." << endl;
cout << "\nQual simbolo o primeiro jogador deseja usar?\n " << endl;
cin >> simboloJG1;
cout << "\nQual simbolo o segundo jogador deseja usar? (Escolha um simbolo diferente de " << simboloJG1 << " ).\n" << endl;
cin >> simboloJG2;

while(simboloJG2==simboloJG1){
    cout << "\nSimbolo ja escolhido pelo primeiro jogador, Escolha um que não esteja em uso: \n" << endl;
    cin >> simboloJG2;
} 

char p1 = '1', p2 = '2', p3 = '3';
char p4 = '4', p5 = '5', p6 = '6';
char p7 = '7', p8 = '8', p9 = '9';

int turno = 1;
int jogada;
bool acabou = false;

while(acabou == false){
    cout << "\n--- Turno " << turno << " ---" << endl;
    cout << "\nVeja as possíveis posições:" << endl;
    Tabuleiro(p1, p2, p3, p4, p5, p6, p7, p8, p9);

    char simboloAtual;
    if(turno % 2 !=0 ){
        simboloAtual = simboloJG1;
    } else {
        simboloAtual = simboloJG2;
    }

    cout <<"\n";
    if(turno % 2 !=0 ){
        cout <<  "JOGADOR 1";
    } 
    else 
    {
        cout <<  "JOGADOR 2";
    }
    cout << " (" << simboloAtual << "), sua vez. Escolha um número de 1 a 9 (POSIÇÃO):\n " << endl;
    cin >> jogada;

    bool jogadaValida = false;
    if(jogada >= 1 && jogada <= 9){
       switch(jogada){
        case 1:
             if(p1 != simboloJG1 && p1 != simboloJG2){
                p1=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 2:
             if(p2 != simboloJG1 && p2 != simboloJG2){
                p2=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 3:
             if(p3 != simboloJG1 && p3 != simboloJG2){
                p3=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 4:
             if(p4 != simboloJG1 && p4 != simboloJG2){
                p4=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 5:
             if(p5 != simboloJG1 && p5 != simboloJG2){
                p5=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 6:
             if(p6 != simboloJG1 && p6 != simboloJG2){
                p6=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 7:
             if(p7 != simboloJG1 && p7 != simboloJG2){
                p7=simboloAtual;
                jogadaValida = true;
            }
            break;  
        case 8:
             if(p8 != simboloJG1 && p8 != simboloJG2){
                p8=simboloAtual;
                jogadaValida = true;
            }
            break;
        case 9:
             if(p9 != simboloJG1 && p9 != simboloJG2){
                p9=simboloAtual;
                jogadaValida = true;
            }
            break;   
       }
    }

    if(jogadaValida==true){
    cout << "\n----------------------------------------------------\n" << endl;

    if(vitoria(simboloAtual, p1, p2, p3, p4, p5, p6, p7, p8, p9)){
        cout << "           O JOGO ACABOU!!!\n\n";
        Tabuleiro(p1, p2, p3, p4, p5, p6, p7, p8, p9);
        cout << "\n Parebéns, ";
        if(turno % 2 !=0){
            cout << "Jogador 1";
        } else {
            cout << "Jogador 2";
        }
        cout << "! Você GANHOU o jogo!" << endl;

        acabou = true;

    } else if(empate(p1, p2, p3, p4, p5, p6, p7, p8, p9)){
        cout << "FIM DE JOGO!\n" << endl;
        Tabuleiro(p1, p2, p3, p4, p5, p6, p7, p8, p9);
        cout << "\nEMPATE!" << endl;

        acabou = true;
    }
    turno++;
} else {
    cout <<"\nPosição inválida ou já ocupada, tente OUTRA posição! \n";
    cout << "\n----------------------------------------------------\n" << endl;
}
    }
    return 0;

    }
