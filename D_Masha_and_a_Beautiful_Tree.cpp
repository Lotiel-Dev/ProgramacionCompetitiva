#include <bits/stdc++.h>
using namespace std;

void resolver() {
    int n; 
    cin >> n;
    vector<int> arbol(n);
    for (int i = 0; i < n; i++) {
        cin >> arbol[i];
    }

    int distancia = 2;
    int respuesta = 0;
    while (distancia <= n) {
        for (int i = 0; i < n; i += distancia) {
            if (abs(arbol[i] - arbol[i + distancia / 2]) > distancia / 2) {
                cout << -1 << "\n";
                return;
            }
            if (arbol[i] > arbol[i + distancia / 2]) {
                swap(arbol[i], arbol[i + distancia / 2]);
                respuesta++;
            }
        }
        distancia *= 2;
    }

    cout << respuesta << "\n";
}

int main() {
    int casos; 
    cin >> casos;
    while (casos--) {
        resolver();
    }
}
