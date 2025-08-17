//#include <bits/stdc++.h>
//#define int long long
#include <iostream>
#include <string>
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;


double calcula(int esq, int dir){
    if(esq == dir){
        return 1.0;
    }
    int meio = (dir + esq)/2;
    int total = dir - esq + 1;
    int quant_esq = meio - esq + 1;
    int quant_dir = dir - meio;
    return (1.0 + (calcula(esq, meio) * ((double)quant_esq/total))
    + (calcula(meio + 1, dir) * ((double) quant_dir/total)));
    
}

int main()
{

    /* Imprimir o numero esperado de perguntas necessarias
    para descobrir qual peixe foi o escolhido 
    
    Ideia é quebrar os conjuntos em dois subconjuntos, fazer meio que uma busca binaria 
    calcular a esperanca de cada subconjunto + 1 para considerar a pergunta que estou fazendo.

    Base da recursao: se eu so tenho 1 peixe, o numero esperado de perguntas é 1.
    
    */

    int n = 0, esq = 0;
    double esperado = 0;
    string peixe;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> peixe;
    }
    esperado = calcula(esq, n - 1);
    cout << esperado << endl;
    return 0;
}
