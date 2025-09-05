#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string a;
    string b;
    string H;
    string aux;
    cin >> a;
    cin >> b;
    cin >> H;
    std::unordered_map<char, int> conteoH;
    std::unordered_map<char, int> conteoAB;
    aux= a + b;
    // Recorremos cada letra de la palabra

    for (char c : H) {
        conteoH[c]++;  // Si no existe, empieza en 0 y luego se incrementa
    }

    for (char c : aux) {
        conteoAB[c]++;  // Si no existe, empieza en 0 y luego se incrementa
    }
    
    bool sonIguales = true;

// 1. Verificar tamaños
if (conteoH.size() != conteoAB.size()) {
    sonIguales = false;
} else {
    // 2. Recorrer un mapa y comparar con el otro
    for (const auto &p : conteoH) {
        char letra = p.first;
        int cantidad = p.second;

        // Si la letra no existe en conteoAB o la cantidad difiere
        if (conteoAB.find(letra) == conteoAB.end() || conteoAB.at(letra) != cantidad) {
            sonIguales = false;
            break;
        }
    }
}

// Mostrar resultado
if (sonIguales) {
    cout << "YES\n";
} else {
    cout << "NO\n";
}


    return 0;
}
