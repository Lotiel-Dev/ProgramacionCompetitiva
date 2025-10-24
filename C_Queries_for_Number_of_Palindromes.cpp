#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const char nl = '\n';
const int MX = 5005;

string cad;
ll consultas;
bool es_pal[MX][MX];
ll sum_pal[MX][MX]; // DP: suma de palíndromos en rango [i][j]

void precomputar() {
    for (ll longi = 1; longi <= cad.size(); ++longi) {
        for (ll i = 0; i + longi <= cad.size(); ++i) {
            ll j = i + longi - 1;
            
            if (longi == 1) {
                es_pal[i][j] = 1;
            } else if (longi == 2) {
                es_pal[i][j] = (cad[i] == cad[j]);
            } else {
                es_pal[i][j] = (cad[i] == cad[j] && es_pal[i + 1][j - 1]);
            }

            if (longi == 1) {
                sum_pal[i][j] = 1;
            } else {
                sum_pal[i][j] = es_pal[i][j] + sum_pal[i][j - 1] + sum_pal[i + 1][j] - sum_pal[i + 1][j - 1];
            }
        }
    }
}

void resolver(int test) {
    cin >> cad >> consultas;
    precomputar();
    
    for (ll i = 0; i < consultas; ++i) {
        ll izq, der;
        cin >> izq >> der;
        izq--, der--;
        cout << sum_pal[izq][der] << nl;
    }
}

bool multiples_casos = 0;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    ll num_casos = 1;
    if (multiples_casos) {
        cin >> num_casos;
    }
    for (ll i = 1; i <= num_casos; ++i) {
        resolver(i);
    }
    
    return 0;
}