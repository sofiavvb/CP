#include <bits/stdc++.h>
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

    int n, count = 0, tava_balanceado = 0, teto = 0;
    char c;
    vector<int> map;
    //map[0] "(" e map[1] = ")"
    map = {0,0};
    vector<int> seq_mudada; //2x de tamanho

    cin >> n;
   for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == '('){
            map[0]++;
        }else{
            map[1]++;
        }

        if (map[1] > map[0] && map[1] < n/2){
            count++;
        }else if(map[1] == map[0] && map[1] < n/2){
            
            if (count >1 && map[0] < n/2){
                count--;
            }
            tava_balanceado = 1;
        }
    }

    //checo se eh valida
    //nao eh? movo um pro final e checo se eh valida ate ser (conto quantas vezes fiz isso).

        
    cout << count << endl;
}
