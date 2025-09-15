//https://codeforces.com/submissions/ADRIaaaaa
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> conjunto_ordenado;

const int NUM_BORDES = 4;
int ancho, alto;

vector<vector<pair<int, int>>> puntos_borde(NUM_BORDES);

bool esta_en_borde(int x, int y, int id_punto) {
    if (y == 0) {
        puntos_borde[0].emplace_back(x, id_punto);
        return true;
    }
    if (x == ancho) {
        puntos_borde[1].emplace_back(y, id_punto);
        return true;
    }
    if (y == alto) {
        puntos_borde[2].emplace_back(-x, id_punto);
        return true;
    }
    if (x == 0) {
        puntos_borde[3].emplace_back(-y, id_punto);
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> ancho >> alto;
    int num_segmentos;
    cin >> num_segmentos;
    
    vector<int> contador_borde(num_segmentos, 0);
    
    for (int i = 0; i < num_segmentos; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        contador_borde[i] += esta_en_borde(x1, y1, i);
        contador_borde[i] += esta_en_borde(x2, y2, i);
    }
    
    vector<pair<int, int>> puntos_ordenados;
    
    for (int borde = 0; borde < NUM_BORDES; borde++) {
        sort(puntos_borde[borde].begin(), puntos_borde[borde].end());
        for (const auto &punto : puntos_borde[borde]) {
            puntos_ordenados.push_back(punto);
        }
    }
    
    stack<int> pila;
    vector<int> contador_apariciones(num_segmentos, 0);
    
    for (const auto &punto : puntos_ordenados) {
        int id_segmento = punto.second;
        
        if (contador_borde[id_segmento] != 2) continue;
        
        contador_apariciones[id_segmento]++;
        
        if (contador_apariciones[id_segmento] == 2) {
            if (pila.empty() || pila.top() != id_segmento) {
                cout << "N";
                return 0;
            }
            pila.pop();
        } else {
            pila.push(id_segmento);
        }
    }
    
    cout << "Y";
    return 0;
}


///////////////////////////////////////////////DEEPSEEK lo Reescribio /////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, h, n;
    cin >> w >> h >> n;
    
    vector<pair<int, int>> puntos[4];
    vector<int> cnt_borde(n, 0);
    
    auto agregar_punto = [&](int x, int y, int id) {
        if (y == 0) puntos[0].push_back({x, id});
        else if (x == w) puntos[1].push_back({y, id});
        else if (y == h) puntos[2].push_back({-x, id});
        else if (x == 0) puntos[3].push_back({-y, id});
        else return false;
        return true;
    };
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cnt_borde[i] += agregar_punto(x1, y1, i);
        cnt_borde[i] += agregar_punto(x2, y2, i);
    }
    
    vector<pair<int, int>> recorrido;
    for (int i = 0; i < 4; i++) {
        sort(puntos[i].begin(), puntos[i].end());
        for (auto p : puntos[i]) recorrido.push_back(p);
    }
    
    stack<int> st;
    vector<int> apariciones(n, 0);
    
    for (auto p : recorrido) {
        int id = p.second;
        if (cnt_borde[id] != 2) continue;
        
        if (++apariciones[id] == 2) {
            if (st.empty() || st.top() != id) {
                cout << "N";
                return 0;
            }
            st.pop();
        } else {
            st.push(id);
        }
    }
    
    cout << "Y";
    return 0;
}