#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    int n, m, curr, x;
    vector<int> A;
    map<int, int> ocorrencias;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        A.push_back(x);
        ocorrencias[x]++;
    }
    for (int i = 0; i < m; ++i) {
        cin >> curr;
        if(ocorrencias[curr]){
            ocorrencias[curr]--;
        }
    }
    for (const auto& par : ocorrencias) {
        if (par.second != 0) {
            for (int i = 0; i < par.second; ++i) {
                cout << par.first << " ";
            }
        }
}
    
}