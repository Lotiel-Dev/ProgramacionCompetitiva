#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

bool verif(int lon, const string &cad, int tam) {
    if (lon > tam - 2) {
        return false;
    }
    
    long long h_obj = 0;
    long long pot_max = 1;
    
    for (int i = 0; i < lon; i++) {
        h_obj = (h_obj * 31 + (cad[i] - 'a' + 1)) % mod;
        if (i < lon - 1) {
            pot_max = (pot_max * 31) % mod;
        }
    }

    long long h_act = 0;
    for (int i = 1; i <= lon; i++) {
        h_act = (h_act * 31 + (cad[i] - 'a' + 1)) % mod;
    }

    if (h_act == h_obj) {
        return true;
    }

    for (int i = lon + 1; i < tam - 1; i++) {
        long long val_quit = ((cad[i - lon] - 'a' + 1) * pot_max) % mod;
        h_act = (h_act - val_quit + mod) % mod;
        h_act = (h_act * 31 + (cad[i] - 'a' + 1)) % mod;
        
        if (h_act == h_obj) {
            return true;
        }
    }
    
    return false;
}

void solucion() {
    string cad;
    cin >> cad;
    int tam = cad.size();
    
    if (tam < 3) {
        cout << "Just a legend\n";
        return;
    }

    long long h_izq = 0, h_der = 0;
    long long pot = 1;
    vector<int> pos;

    for (int i = 0; i < tam - 1; i++) {
        h_izq = (h_izq * 31 + (cad[i] - 'a' + 1)) % mod;
        h_der = (h_der + (pot * (cad[tam - 1 - i] - 'a' + 1)) % mod) % mod;
        pot = (pot * 31) % mod;

        if (h_izq == h_der) {
            pos.push_back(i + 1);
        }
    }

    if (pos.empty()) {
        cout << "Just a legend\n";
        return;
    }

    int ini = 0, fin = pos.size() - 1;
    int res = -1;

    while (ini <= fin) {
        int med = ini + (fin - ini) / 2;
        if (verif(pos[med], cad, tam)) {
            res = med;
            ini = med + 1;
        } else {
            fin = med - 1;
        }
    }

    if (res == -1) {
        cout << "Just a legend\n";
    } else {
        cout << cad.substr(0, pos[res]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    solucion();
    return 0;
}