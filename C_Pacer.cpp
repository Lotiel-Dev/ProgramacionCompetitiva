#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> tiempos(n);
    vector<int> lados(n);
    
    for (int i = 0; i < n; i++) {
        cin >> tiempos[i] >> lados[i];
    }
    
    long long tiempo_actual = 0;
    int lado_actual = 0;
    long long puntos = 0;
    
    for (int i = 0; i < n; i++) {
        long long diferencia_tiempo = tiempos[i] - tiempo_actual;
        int paridad_requerida = lado_actual ^ lados[i];
        long long movimientos;
        
        if (diferencia_tiempo % 2 == paridad_requerida) {
            movimientos = diferencia_tiempo;
        } else {
            movimientos = diferencia_tiempo - 1;
        }
        
        puntos += movimientos;
        tiempo_actual = tiempos[i];
        lado_actual = lados[i];
    }
    
    puntos += (m - tiempo_actual);
    
    cout << puntos << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}