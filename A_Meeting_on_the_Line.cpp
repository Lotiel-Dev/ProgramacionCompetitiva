#include <bits/stdc++.h>
using namespace std;

bool verif(long long mit, int n, vector<long long> &pos, vector<long long> &tiem) {
    if (mit < 0) {
        return false;
    }
    long long izq = pos[0] + tiem[0] - mit;
    long long der = pos[0] - tiem[0] + mit;

    for (int i = 1; i < n; i++) {
        long long t1 = pos[i] + tiem[i] - mit;
        long long t2 = pos[i] - tiem[i] + mit;
        if (t1 > izq) {
            izq = t1;
        }
        if (t2 < der) {
            der = t2;
        }
    }

    if (der >= izq) {
        return true;
    }
    return false;
}

void solucion() {
    int n;
    cin >> n;
    vector<long long> pos(n), tiem(n);

    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> tiem[i];
        pos[i] *= 2;
        tiem[i] *= 2;
    }

    long long ini = -1;
    long long fin = 2e9;

    while (fin - ini > 1) {
        long long mit = (ini + fin) / 2;
        if (verif(mit, n, pos, tiem)) {
            fin = mit;
        } else {
            ini = mit;
        }
    }

    long long izq = pos[0] + tiem[0] - fin;
    long long der = pos[0] - tiem[0] + fin;

    for (int i = 1; i < n; i++) {
        long long t1 = pos[i] + tiem[i] - fin;
        long long t2 = pos[i] - tiem[i] + fin;
        if (t1 > izq) {
            izq = t1;
        }
        if (t2 < der) {
            der = t2;
        }
    }

    if (n == 1) {
        der = pos[0];
    }

    cout << der / 2;
    if (der % 2 != 0) {
        cout << ".5";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solucion();
    }


    return 0;
}