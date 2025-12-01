//simon modificado por chatsito
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200000 + 5;

int cantidadCadenas, mejorPrefijo;
string objetivo, cadenas[MAXN], resto[MAXN];

signed main() {
    scanf("%lld", &cantidadCadenas);

    for (int i = 1; i <= cantidadCadenas; i++)
        cin >> cadenas[i];

    cin >> objetivo;

    for (int i = 1; i <= cantidadCadenas; i++) {
        int pos = 0;
        for (char c : cadenas[i]) {
            if (pos < objetivo.size() && objetivo[pos] == c)
                pos++;
            else
                resto[pos] += c;
        }
        mejorPrefijo = max(mejorPrefijo, pos);
    }

    if (mejorPrefijo == objetivo.size()) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    for (int i = 0; i < objetivo.size(); i++) {
        cout << resto[i];
        if (mejorPrefijo > i)
            printf("%c", objetivo[i]);
    }

    return 0;
}


//mi chatsito
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cantidad;
    if (!(cin >> cantidad)) return 0;

    vector<string> cadenas(cantidad);
    long long totalCaracteres = 0;
    for (int i = 0; i < cantidad; i++) {
        cin >> cadenas[i];
        totalCaracteres += cadenas[i].size();
    }

    string prohibido;
    cin >> prohibido;

    vector<int> avance(cantidad, 0);
    vector<vector<int>> listas(26);

    int pendientes = cantidad;

    for (int i = 0; i < cantidad; i++) {
        int letra = cadenas[i][0] - 'a';
        listas[letra].push_back(i);
    }

    string salida;
    salida.reserve(min<long long>(totalCaracteres, 1'000'000));

    int posProhibido = 0;
    bool fallo = false;

    vector<int> procesar;

    while (pendientes > 0) {
        if (posProhibido == (int)prohibido.size()) {
            fallo = true;
            break;
        }

        int letraObjetivo = (posProhibido < (int)prohibido.size()) ? prohibido[posProhibido] - 'a' : -1;
        int eleccion = -1;

        if (letraObjetivo != -1) {
            for (int c = 0; c < 26; c++) {
                if (!listas[c].empty() && c != letraObjetivo) {
                    eleccion = c;
                    break;
                }
            }
        }

        if (eleccion == -1) {
            for (int c = 0; c < 26; c++) {
                if (!listas[c].empty()) {
                    eleccion = c;
                    break;
                }
            }
        }

        if (eleccion == -1) {
            fallo = true;
            break;
        }

        char caracter = char('a' + eleccion);
        salida.push_back(caracter);

        if (posProhibido < (int)prohibido.size() && caracter == prohibido[posProhibido]) {
            posProhibido++;
            if (posProhibido == (int)prohibido.size()) {
                fallo = true;
                break;
            }
        }

        procesar.swap(listas[eleccion]);

        for (int id : procesar) {
            int &p = avance[id];
            p++;
            if (p == (int)cadenas[id].size()) {
                pendientes--;
            } else {
                int sig = cadenas[id][p] - 'a';
                listas[sig].push_back(id);
            }
        }

        procesar.clear();
    }

    if (!fallo && pendientes == 0) {
        cout << "YES\n" << salida << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
//Simon mejoradito

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> cadenas(n);
    for (auto &s : cadenas) {
        cin >> s;
    }

    string objetivo;
    cin >> objetivo;

    int mejorPrefijo = 0;
    vector<string> resto(objetivo.size() + 1);

    for (const auto &cad : cadenas) {
        int pos = 0;
        for (char c : cad) {
            if (pos < (int)objetivo.size() && objetivo[pos] == c) {
                pos++;
            } else {
                resto[pos] += c;
            }
        }
        mejorPrefijo = max(mejorPrefijo, pos);
    }

    if (mejorPrefijo == (int)objetivo.size()) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < (int)objetivo.size(); i++) {
        cout << resto[i];
        if (i < mejorPrefijo)
            cout << objetivo[i];
    }

    return 0;
}
