//Aquí implemento la versión fácil (eficiente para N ≤ 2000).
//En la versión fácil (𝑁≤2000), se puede buscar linealmente (O(N)) para la operación tipo 3 P y.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // número de casos de prueba

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;  // número de operaciones

        deque<int> q;
        cout << "Case " << tc << ":\n";

        for (int i = 0; i < N; i++) {
            int type;
            char x;
            cin >> type >> x;

            if (type == 1) { 
                // Insertar
                int y;
                cin >> y;
                if (x == 'B') q.push_back(y);
                else q.push_front(y);
            } 
            else if (type == 2) { 
                // Eliminar
                if (x == 'B') q.pop_back();
                else q.pop_front();
            } 
            else if (type == 3) { 
                // Consultar
                int y;
                cin >> y;
                if (x == 'D') {
                    // Obtener ID en la posición y (1-indexada)
                    cout << q[y - 1] << "\n";
                } else { 
                    // Obtener posición de ID = y
                    for (int j = 0; j < (int)q.size(); j++) {
                        if (q[j] == y) {
                            cout << j + 1 << "\n";
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


///////////////// FUnciona pero sale Time Limitid para casos 𝑁≤200000 <///////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // número de casos de prueba

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        deque<int> q;
        unordered_map<int, int> pos; // ID -> posición relativa
        cout << "Case " << tc << ":\n";

        for (int i = 0; i < N; i++) {
            int type;
            char x;
            cin >> type >> x;

            if (type == 1) {
                // Insertar
                int y;
                cin >> y;
                if (x == 'B') {
                    q.push_back(y);
                    pos[y] = (int)q.size() - 1; // posición relativa
                } else {
                    q.push_front(y);
                    // todas las posiciones relativas cambian
                    // solución: actualizar solo este
                    for (auto &kv : pos) kv.second++;
                    pos[y] = 0;
                }
            } 
            else if (type == 2) {
                // Eliminar
                if (x == 'B') {
                    int rem = q.back();
                    q.pop_back();
                    pos.erase(rem);
                } else {
                    int rem = q.front();
                    q.pop_front();
                    pos.erase(rem);
                    // ajustar posiciones
                    for (auto &kv : pos) kv.second--;
                }
            } 
            else if (type == 3) {
                // Consultar
                int y;
                cin >> y;
                if (x == 'D') {
                    // ID en la posición y
                    cout << q[y - 1] << "\n";
                } else {
                    // Posición de ID = y
                    cout << pos[y] + 1 << "\n";
                }
            }
        }
    }
    return 0;
}

////////////////////////////// Version Final Funciona para todo//////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // número de casos

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        // arreglo central de tamaño suficiente
        vector<int> arr(2 * N + 5);
        unordered_map<int, int> pos; // ID -> índice en arr
        pos.reserve(N * 2);

        int base = N;   // centro
        int L = base, R = base - 1; // inicialmente vacío

        cout << "Case " << tc << ":\n";

        for (int i = 0; i < N; i++) {
            int type;
            char x;
            cin >> type >> x;

            if (type == 1) {
                int y;
                cin >> y;
                if (x == 'B') {
                    R++;
                    arr[R] = y;
                    pos[y] = R;
                } else { // 'F'
                    L--;
                    arr[L] = y;
                    pos[y] = L;
                }
            } 
            else if (type == 2) {
                if (x == 'B') {
                    pos.erase(arr[R]);
                    R--;
                } else { // 'F'
                    pos.erase(arr[L]);
                    L++;
                }
            } 
            else if (type == 3) {
                int y;
                cin >> y;
                if (x == 'D') {
                    cout << arr[L + y - 1] << "\n";
                } else { // 'P'
                    cout << pos[y] - L + 1 << "\n";
                }
            }
        }
    }
    return 0;
}
