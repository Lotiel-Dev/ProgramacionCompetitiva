#include <bits/stdc++.h>
using namespace std;

int t, k;
string cadena;

vector<vector<int>> memoTabla;

int totalParticiones; 
vector<unordered_set<int>> particiones;

int resolver(int indice, int ultimoChar) {
    if (indice == totalParticiones) 
        return 0;

    if (memoTabla[indice][ultimoChar] != -1) 
        return memoTabla[indice][ultimoChar];

    int cantidadUnicos = particiones[indice].size();
    int mejorCosto = INT_MAX;

    for (int primerChar : particiones[indice]) {
        for (int ultimoCharActual : particiones[indice]) {
            if (cantidadUnicos == 1 || primerChar != ultimoCharActual) {
                int costo = resolver(indice + 1, ultimoCharActual) + cantidadUnicos;
                if (ultimoChar == primerChar)
                    costo--;
                mejorCosto = min(mejorCosto, costo);
            }
        }
    }

    return memoTabla[indice][ultimoChar] = mejorCosto;
}

int main() {
    scanf("%d", &t);

    while (t--) {
        cin >> k >> cadena;

        totalParticiones = cadena.length() / k;

        memoTabla.assign(totalParticiones, vector<int>(27, -1));
        particiones.assign(totalParticiones, unordered_set<int>());

        for (int i = 0; i < totalParticiones; i++) {
            for (int j = 0; j < k; j++) {
                int pos = i * k + j;
                particiones[i].insert(cadena[pos] - 'a');
            }
        }

        printf("%d\n", resolver(0, 26));
    }
}
