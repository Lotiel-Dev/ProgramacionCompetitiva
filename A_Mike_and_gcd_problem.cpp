#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void resolver_caso() {
    
    ll tam;
    cin >> tam;
    
    vector<ll> arr(tam);
    for (ll i = 0; i < tam; i++) {
        cin >> arr[i];
    }
    
    ll mcd = arr[0];
    for (ll i = 1; i < tam; i++) {
        mcd = __gcd(arr[i], mcd); 
    }
    
    cout << "YES" << "\n";
    
    if (mcd > 1) {
        cout << 0 << "\n";
        return;
    }
    
    ll resp = 0;
    ll cont_imp = 0;
    
    for (ll i = 0; i < tam; i++) {
        if (arr[i] % 2 == 1) {
            cont_imp++; 
        } 
        else {
            if (cont_imp > 0) {
                resp += cont_imp / 2;
                if (cont_imp % 2 == 1) {
                    resp += 2;
                }
                cont_imp = 0; 
            }
        }
    }
    
    if (cont_imp > 0) {
        resp += cont_imp / 2;
        if (cont_imp % 2 == 1) {
            resp += 2;
        }
    }
    
    cout << resp << "\n";
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);                  
    cout.tie(0);                 
    
    cout << fixed << setprecision(10);
    
    ll num_casos = 1;
    
    for (ll i = 1; i <= num_casos; i++) {
        resolver_caso();
    }
    
    return 0;
}