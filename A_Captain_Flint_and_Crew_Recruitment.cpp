#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimiza la velocidad de entrada y salida de datos.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long casos;
    cin >> casos;

    while (casos--) {
        long long num;
        cin >> num;

        if (num <= 30) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            // Casos especiales para n=36, n=40 y n=44
            if (num == 36 || num == 40 || num == 44) {
                cout << 6 << " " << 10 << " " << 15 << " " << num - 31 << "\n";
            } else {
                // Caso general para n > 30
                cout << 6 << " " << 10 << " " << 14 << " " << num - 30 << "\n";
            }
        }
    }

    return 0;
}