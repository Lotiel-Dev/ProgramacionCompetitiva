#include <bits/stdc++.h>
using namespace std;

int main() {
    string cadena;

    while (getline(cin, cadena)) {
        int n = cadena.length();
        vector<vector<int>> dp(n, vector<int>(n, 1e6));
        vector<vector<int>> mov(n, vector<int>(n));

        for (int tam = 0; tam < n; tam++) {
            for (int i = 0; i + tam < n; i++) {
                int j = i + tam;

                if (cadena[i] == cadena[j]) {
                    dp[i][j] = (i + 1 >= j - 1) ? 0 : dp[i + 1][j - 1];
                } else {
                    int costoIzq = dp[i][j - 1];
                    int costoDer = dp[i + 1][j];

                    if (costoIzq > costoDer) {
                        dp[i][j] = costoDer + 1;
                        mov[i][j] = 1;
                    } else {
                        dp[i][j] = costoIzq + 1;
                        mov[i][j] = 2;
                    }
                }
            }
        }

        int l = 0, r = n - 1;
        string parteIzq = "", parteDer = "";

        while (l <= r) {
            if (cadena[l] == cadena[r]) {
                if (l == r) parteIzq += cadena[l];
                else {
                    parteIzq += cadena[l];
                    parteDer += cadena[l];
                }
                l++; r--;
            } else if (mov[l][r] == 1) {
                parteIzq += cadena[l];
                parteDer += cadena[l];
                l++;
            } else {
                parteIzq += cadena[r];
                parteDer += cadena[r];
                r--;
            }
        }

        reverse(parteDer.begin(), parteDer.end());
        cout << dp[0][n - 1] << " " << parteIzq << parteDer << endl;
    }
}
