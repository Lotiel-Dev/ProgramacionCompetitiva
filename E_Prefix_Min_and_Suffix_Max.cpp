#include <bits/stdc++.h>
using namespace std;

void resolver() {
    int n;
    cin >> n;

    vector<int> numeros(n);
    for (auto &x : numeros) {
        cin >> x;
    }

    vector<int> prefijo_min(n), sufijo_max(n);

    // calcular mínimos prefijos
    prefijo_min[0] = numeros[0];
    for (int i = 1; i < n; i++) {
        prefijo_min[i] = min(prefijo_min[i - 1], numeros[i]);
    }

    // calcular máximos sufijos
    sufijo_max[n - 1] = numeros[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sufijo_max[i] = max(sufijo_max[i + 1], numeros[i]);
    }

    string respuesta;
    for (int i = 0; i < n; i++) {
        if (numeros[i] == prefijo_min[i] || numeros[i] == sufijo_max[i]) {
            respuesta += '1';
        } else {
            respuesta += '0';
        }
    }

    cout << respuesta << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int casos;
    cin >> casos;
    while (casos--) {
        resolver();
    }
    return 0;
}
