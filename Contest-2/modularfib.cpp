#include <cstdio>
#include <cstdlib>
using namespace std;

// Tipo long long
typedef long long ll;

// Dimensão da matriz (2x2 para Fibonacci)
#define MAX_N 2

// Módulo global
ll MOD;

// Estrutura de matriz 2x2
struct Matrix {
    ll mat[MAX_N][MAX_N];
};

// Multiplicação de matrizes (modular)
Matrix matMul(const Matrix &a, const Matrix &b) {
    Matrix ans;
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            ans.mat[i][j] = 0;
            for (int k = 0; k < MAX_N; k++) {
                ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
                ans.mat[i][j] %= MOD;
            }
        }
    }
    return ans;
}

// Exponenciação rápida de matriz
Matrix matPow(Matrix base, ll n) {
    // Inicializa como matriz identidade
    Matrix ans;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            ans.mat[i][j] = (i == j ? 1 : 0);

    // Loop de exponenciação binária
    while (n > 0) {
        if (n % 2)              // Se n é ímpar
            ans = matMul(ans, base);  // Acumula o fator
        base = matMul(base, base);    // Eleva base ao quadrado
        n /= 2;                        // Divide n por 2
    }
    return ans;
}

int main() {
    int n, p;

    // Lê pares n e p até EOF
    while (scanf("%d %d", &n, &p) == 2) {
        // Inicializa a matriz de Fibonacci
        Matrix fib;
        fib.mat[0][0] = 1; fib.mat[0][1] = 1;
        fib.mat[1][0] = 1; fib.mat[1][1] = 0;

        // Calcula MOD = 2^p
        MOD = 1;
        for (int i = 0; i < p; i++)
            MOD *= 2;

        // Calcula fib^n
        Matrix ans = matPow(fib, n);

        // Imprime F_n modulo 2^p
        printf("%lld\n", ans.mat[0][1]);
    }

    return 0;
}
