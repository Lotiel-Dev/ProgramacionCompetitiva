#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string linea;
    getline(cin, linea); // Consumir el salto de línea después de n
    getline(cin, linea);
    stringstream ss(linea);
    vector<string> tokens;
    string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    stack<pair<int, long long>> pila;
    int operacion_actual = 0; // 0: suma, 1: multiplicación
    long long valor_actual = 0;
    
    for (auto &token_actual : tokens) {
        if (token_actual == "(") {
            pila.push({operacion_actual, valor_actual});
            operacion_actual = (operacion_actual == 0) ? 1 : 0;
            valor_actual = (operacion_actual == 0) ? 0 : 1;
        } else if (token_actual == ")") {
            auto [operacion_anterior, valor_anterior] = pila.top();
            pila.pop();
            if (operacion_anterior == 0) {
                valor_actual = (valor_anterior + valor_actual) % MOD;
            } else {
                valor_actual = (valor_anterior * valor_actual) % MOD;
            }
            operacion_actual = operacion_anterior;
        } else {
            long long numero = stoll(token_actual);
            if (operacion_actual == 0) {
                valor_actual = (valor_actual + numero) % MOD;
            } else {
                valor_actual = (valor_actual * numero) % MOD;
            }
        }
    }
    
    cout << valor_actual % MOD << "\n";
    
    return 0;
}