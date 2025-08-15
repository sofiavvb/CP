#include <iostream>
#include <vector>
using namespace std;

int main(){
    string word;
    int diff = 0;
    cin >> word;

    string reversed_word = word;
    reverse(reversed_word.begin(), reversed_word.end());
    //se eh palindromo
    if (word == reversed_word) {
        if(word.length() % 2 == 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }else{
        for(int i = 0; i < word.length() / 2; ++i){
            if(word[i] != reversed_word[i]){
                diff++;
            }
        }
        if (diff == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}