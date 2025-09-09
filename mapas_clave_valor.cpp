#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int testCases; cin >> testCases;
    string caso;
    vector<string> resultado(testCases);
    std::unordered_map<char, int> conteo;
    std::unordered_map<char, int> conteo2;
 
    while(testCases--){
        cin >> caso;
        int mitad = caso.size() / 2;
        for (int i = 0; i < mitad; i++) {
            char c = caso[i];
            conteo[c]++;
        }
 
        for (int i = mitad; i < caso.size(); i++){
            char c = caso[i];
            conteo2[c]++; 
        }
 
        bool sonIguales = true;
 
        if (conteo.size() != conteo2.size()) {
            sonIguales = false;
        } else {
            for (const auto &p : conteo) {
                char letra = p.first;
                int cantidad = p.second;
         
                if (conteo2.find(letra) == conteo2.end() || conteo2.at(letra) != cantidad) {
                    sonIguales = false;
                    break;
                }
            }
        }
         
        if (sonIguales) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
 
 
    }
 
    return 0;
}