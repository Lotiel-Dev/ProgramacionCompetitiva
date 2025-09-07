#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main(){
    int testcases; cin >> testcases;
    vector<ll> resultado(testcases,-1);
    
    for (int i = 0; i < testcases; i++){
        ll a,b;
        cin >> a >> b;
        ll best = -1;

        vector<ll> divisores;
        for (ll x = 1; x*x <= b; x++){
            
            if(b%x == 0 ){
                divisores.push_back(x);
                if(x != b/x){
                    divisores.push_back(b/x);

                }
                
            }
        }

        for (ll k : divisores){
            ll suma = a*k + b/k;
            if(suma%2 == 0){
                if(suma > best){
                    best = suma;
                }
            }
        }

        resultado[i] = best;
        
    }
    for (int i = 0; i < testcases; i++){
        cout << resultado[i] << endl;
    }
    
    return 0;
}