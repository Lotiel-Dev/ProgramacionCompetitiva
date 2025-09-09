#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int testCases, suma=0, suma2=0; cin >> testCases;
    string caso;
    vector<string> resultado;
    
 
    while(testCases--){
        cin >> caso;
        int mitad = caso.size() / 2;
        for (int i = 0; i < mitad; i++) {
            suma=suma+caso[i];
        }
 
        for (int i = mitad; i < caso.size(); i++){
            suma2 = suma2 + caso[i];
        }
 
        if(suma == suma2){
            resultado.push_back("YES");
        }else{
            resultado.push_back("NO");
        }
 
        suma = 0;
        suma2 = 0;
 
    }
 
    for (string i : resultado){
        cout << i << endl;
    }
    return 0;
}