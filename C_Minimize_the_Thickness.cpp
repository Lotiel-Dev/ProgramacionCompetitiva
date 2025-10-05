#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int suma_total = 0;
        int max_elemento = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            suma_total += a[i];
            max_elemento = max(max_elemento, a[i]);
        }
        
        int ans = n; // Máximo posible: un segmento
        
        // Intentar dividir en k segmentos
        for (int k = 1; k <= n; k++) {
            if (suma_total % k != 0) continue;
            
            int target = suma_total / k;
            if (target < max_elemento) continue;
            
            int suma_actual = 0;
            int largo_actual = 0;
            int max_largo = 0;
            bool valido = true;
            
            for (int i = 0; i < n; i++) {
                suma_actual += a[i];
                largo_actual++;
                
                if (suma_actual == target) {
                    max_largo = max(max_largo, largo_actual);
                    suma_actual = 0;
                    largo_actual = 0;
                } else if (suma_actual > target) {
                    valido = false;
                    break;
                }
            }
            
            if (valido) {
                ans = min(ans, max_largo);
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}