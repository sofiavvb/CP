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

int main()
{

    /* Imprimir o numero esperado de perguntas necessarias para descobrir qual peixe foi o escolhido dentre 10 peixes */

    int n;
    double prob;
    double esperado = 0;
    string peixe;
    cin >> n;
    prob = 1.0 / n;

    for (int i = 1; i <= n; ++i) {
        cin >> peixe;
        esperado += prob * i;
    }
    cout << esperado << endl;
    return 0;
}
