#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(){
    int n, k, curr, prev;
    int sum = 0, idx = 0;
    unordered_map<int, int> window;
    cin >> n >> k;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - k + 1; ++i) {
        if (!i) {
            for (int j = 0; j < k; ++j) {
                curr = numbers[i + j];
                window[curr]++;
                if (window[curr] <= 1){
                    sum++;
                }
            }
            cout << sum << " ";
            continue;
        }

        window[numbers[i-1]]--;
        if (!window[numbers[i-1]]){
            sum--;
        }
        int next = numbers[i+k-1];
        window[next]++;
        if (window[next] <= 1){
            sum++;
        }
        cout << sum << " ";
        //final da janela
        //sum = 0;
        //window.clear();
    }
}