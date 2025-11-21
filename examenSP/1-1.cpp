#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L;
    cin >> n >> L;

    string loco;
    cin >> loco;

    vector<string> vag(n);
    for (int i = 0; i < n; i++) cin >> vag[i];

    // Contar cantidades de cada tipo
    int cnt[4] = {0,0,0,0};
    for (auto &s : vag) {
        if (s == "XX") cnt[0]++;
        else if (s == "XY") cnt[1]++;
        else if (s == "YX") cnt[2]++;
        else cnt[3]++;
    }

    int ini = (loco[1] == 'X') ? 0 : 1;
    int fin = (loco[0] == 'X') ? 0 : 1;

    // Tamaños
    int A = cnt[0] + 1;
    int B = cnt[1] + 1;
    int C = cnt[2] + 1;
    int D = cnt[3] + 1;
    int LADOS = 2;

    // Precalcular saltos para linealizar indices sin bit-shift
    int mulA = B * C * D * LADOS;
    int mulB = C * D * LADOS;
    int mulC = D * LADOS;
    int mulD = LADOS;
    int mulL = 1;

    // Tabla DP
    vector<long long> dp(A * B * C * D * LADOS, 0);

    auto idx = [&](int a, int b, int c, int d, int lado) {
        return a * mulA + b * mulB + c * mulC + d * mulD + lado * mulL;
    };

    // Estado inicial
    dp[idx(0,0,0,0,ini)] = 1;

    // Iterar sobre todos los estados válidos
    for (int a = 0; a <= cnt[0]; a++)
    for (int b = 0; b <= cnt[1]; b++)
    for (int c = 0; c <= cnt[2]; c++)
    for (int d = 0; d <= cnt[3]; d++)
    for (int lado = 0; lado < 2; lado++) {

        long long formas = dp[idx(a,b,c,d,lado)];
        if (formas == 0) continue;

        int usados = a + b + c + d;
        if (usados == L) continue; // ya no se puede extender

        if (lado == 0) {
            // Enganche X
            if (a < cnt[0]) dp[idx(a+1, b, c, d, 0)] += formas;
            if (b < cnt[1]) dp[idx(a, b+1, c, d, 1)] += formas;
        } else {
            // Enganche Y
            if (c < cnt[2]) dp[idx(a, b, c+1, d, 0)] += formas;
            if (d < cnt[3]) dp[idx(a, b, c, d+1, 1)] += formas;
        }
    }

    // Sumar todas las configuraciones que llegan exactamente a L y terminan con el enganche requerido
    long long total = 0;
    for (int a = 0; a <= cnt[0]; a++)
    for (int b = 0; b <= cnt[1]; b++)
    for (int c = 0; c <= cnt[2]; c++)
    for (int d = 0; d <= cnt[3]; d++) {
        if (a + b + c + d == L)
            total += dp[idx(a,b,c,d,fin)];
    }

    cout << total << "\n";
    return 0;
}
