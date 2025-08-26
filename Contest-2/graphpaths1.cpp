#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    //nos numerados de 1 a n
    //grafo esparso (M >> N), vou usar adj
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

}