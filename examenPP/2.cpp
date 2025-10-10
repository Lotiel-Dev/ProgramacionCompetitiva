#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int mitad = n / 2;

    // map para mantener orden por número y lista de palabras
    map<int, vector<string>> grupos;

    for (int i = 0; i < n; i++) {
        int num;
        string palabra;
        cin >> num >> palabra;

        if (i < mitad) palabra = "-";  // primera mitad reemplazada
        grupos[num].push_back(palabra);
    }

    bool primero = true;
    for (auto &par : grupos) {
        for (auto &p : par.second) {
            if (!primero) cout << " ";
            cout << p;
            primero = false;
        }
    }
    cout << "\n";

    return 0;
}
