#include <bits/stdc++.h>
using namespace std;

int num_elems;
vector<int> arr_orig;

bool es_tam_valido(int tam_prueba) {

    if (tam_prueba <= 1) {
        return true;
    }

    vector<int> arr_copia(arr_orig.begin(), arr_orig.begin() + tam_prueba - 1);
    sort(arr_copia.begin(), arr_copia.end());
    
    long long limite = num_elems - tam_prueba;

    for (int valor : arr_copia) {
        if (valor > limite) {
            return false;
        }
        limite++;
    }

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);

    cin >> num_elems;
    
    arr_orig.resize(num_elems);
    for (int i = 0; i < num_elems; ++i) {
        cin >> arr_orig[i];
    }

    int izq = 1;
    int der = num_elems;
    int tam_max_valido = 0;

    while (izq <= der) {
        int med = izq + (der - izq) / 2;

        if (es_tam_valido(med)) {
            tam_max_valido = med;
            izq = med + 1;
        } else {
            der = med - 1;
        }
    }
    
    cout << num_elems - tam_max_valido << std::endl;
    
    return 0;
}