#include <bits/stdc++.h>
using namespace std;


void solve(){
    int impares=0,pares=0;
    bool bandera=false;
    long long suma=0;
    
    int campos; cin >> campos;
    int aux = campos;
    vector<int> camp;
    while (campos--){
        int a; cin >> a;
        camp.push_back(a);
    }

    
    

    for (int i = 0; i < camp.size(); i++){
        if(camp[i]%2 == 0 || bandera){
            suma+= camp[i];
            pares++;
            !bandera;
        }else{
            impares++;
            bandera = i;
        }
    }

    //cout << pares <<endl;
    //cout << impares <<endl;
    //cout << suma <<endl;
    //cout << bandera <<endl;

    if(pares == aux){
        cout << "0" << endl;
    }else{
        cout << suma << endl;
        suma = 0;
        impares = 0;
        pares = 0;
        //bandera = 0;
        
    }
    
    
}


int main (){
    int testcases; cin >> testcases;

    while (testcases--)
    {
        solve();
    }
    
}