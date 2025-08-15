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
    int n, ant, atual, x;
    int count = 1, max = 1;
    vector<int> dias;

    cin >> n;
    for (int i = 0; i < n; ++i) {

        cin >> x;
        dias.push_back(x);
    }

    ant = dias[0];

    for (int i = 1; i < n; ++i) {
        
        atual = dias[i];
        if(atual == ant + 1){
            count++;
        }else{
            count = 1;
        }
        if(count >= max){
            max = count;
        }
        ant = atual;
    }

    cout << max << endl;
}
