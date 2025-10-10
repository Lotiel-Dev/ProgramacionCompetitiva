#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H,E;
    cin >> H >> E;
    vector<int> listHoteles(H);
    vector<int> listElencos(E);
    vector<int> resultado(E);

    //read
    for (int i = 0; i < H; i++) {
        cin >> listHoteles[i];
        //resultado.push_back(2);
    }
    for (int i = 0; i < E; i++) {
        cin >> listElencos[i];
    }
    for (int i = 0; i < E; i++) {
        bool asignado = false;
        for (int j = 0; j < H; j++) {
            if (listHoteles[j] >= listElencos[i]) {
                resultado[i] = j + 1; // hotel j
                listHoteles[j] -= listElencos[i]; // se resta la capacidad
                asignado = true;
                break;
            }
        }
        if (!asignado)
            resultado[i] = 0; // no encontró hotel disponible
    }
    
    




    for (int i : resultado){
        cout << i << " ";
    }
    return 0;
}