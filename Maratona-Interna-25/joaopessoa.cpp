    #include <bits/stdc++.h>
    #include <iostream>
    #define int long long
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

    int32_t main()
    {_
        
        /*Rotacionar parênteses para balancear:*/
        
        //Dada uma string com '(' e ')' (quantidade igual), retorna o
        //número mínimo de caracteres a mover do início para o final
        //para que nenhum prefixo tenha mais ')' que '('.

        // count: saldo de parênteses '(' = +1, ')' = -1
        // prefix: menor saldo encontrado
        // ans: número de caracteres a mover do início para o final

        int n, ans = 0, prefix = 0, count = 0;
        char c;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            if (c == '('){
                count++;
            }else{
                count--;
            }

            if(count < prefix){
                prefix = count;
                ans = i + 1;
            }
            
        }

        cout << ans << endl;
    }
