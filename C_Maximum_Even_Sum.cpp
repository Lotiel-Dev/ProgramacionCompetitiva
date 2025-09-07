#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll mejor = -1;
        
        // Función para probar un divisor k
        auto probar_k = [&](ll k) {
            if (b % k == 0) {
                ll suma = a * k + b / k;
                if (suma % 2 == 0) {
                    if (suma > mejor) mejor = suma;
                }
            }
        };
        
        // Probar los extremos: k=1 y k=b
        probar_k(1);
        probar_k(b);
        
        if (b <= 2000000) {
            // Si b es pequeño, iterar sobre todos los divisores
            for (ll k = 1; k * k <= b; k++) {
                if (b % k == 0) {
                    probar_k(k);
                    probar_k(b / k);
                }
            }
        } else {
            // Si b es grande, probar divisores pequeños (1 a 1000)
            for (ll k = 1; k <= 1000; k++) {
                if (b % k == 0) {
                    probar_k(k);
                    probar_k(b / k);
                }
            }
        }
        
        cout << mejor << endl;
    }
    
    return 0;
}