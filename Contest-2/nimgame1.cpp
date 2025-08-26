#include <iostream>
#include <vector>
using namespace std;

//Nim Game: 
//achar qual jogador ganha um nim game dada alguma configuracao
//ideia é usar simetrias, xor
// [2 2] o jogador ta numa posicao perdedora com pilhas iguais

/*
Se o Nim-sum final é zero, significa que todas as colunas de bits tiveram um resultado 0 no teste de paridade.
 Ou seja, todas as colunas estavam equilibradas. Esse é o nosso estado equilibrado (posição perdedora).

Se o Nim-sum final é diferente de zero, significa que pelo menos um bit no resultado é 1. 
Esse bit 1 corresponde a uma coluna de bits que tinha uma contagem ímpar de 1s. 
Esse é o nosso estado desequilibrado (posição vencedora).*/

int main(){
    int t, n, numero, resultado;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        cin >> resultado;
        for (int j = 1; j < n; j++){
            cin >> numero;
            resultado = resultado ^ numero;
        }
        if(resultado){
            cout << "first" << endl;
        }else{
            cout << "second"<< endl;
        }

    }
}