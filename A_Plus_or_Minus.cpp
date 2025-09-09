#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int testCases; cin >> testCases;
    vector<string> resultado;
    while (testCases--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a + b == c){
            resultado.push_back("+");
        }else{
            resultado.push_back("-");
        }
    }
    for (string i : resultado){
        cout << i << endl;
    }
 
    return 0;
}
