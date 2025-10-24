#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

vector<ll> fact(1e6 + 1);
vector<ll> inv_fact(1e6 + 1);

ll pot_rap(ll n, ll k) {
    if (k == 0) {
        return 1;
    }
    ll a = pot_rap(n, k / 2);
    a = (a * a) % mod;
    
    if (k % 2 == 1) {
        return (a * n) % mod;
    }
    return a;
}

void init() {
    fact[0] = 1;
    inv_fact[0] = 1;
    for (ll i = 1; i <= 1000000; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = pot_rap(fact[i], mod - 2);
    }
}

ll comb(ll n, ll r) {
    if (r < 0 || r > n) {
        return 0;
    }
    ll resp = fact[n];
    ll den = (inv_fact[n - r] * inv_fact[r]) % mod;
    return (resp * den) % mod;
}

void resolver_caso() {
    ll n;
    cin >> n;
    ll suma = 0;
    ll resp = 1;
    
    for (ll i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        suma += val;
        if (i > 0) {
            resp = (resp * comb(suma - 1, val - 1)) % mod;
        }
    }
    cout << resp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    init();
    
    ll num_casos = 1;
    
    while (num_casos--) {
        resolver_caso();
    }
    
    return 0;
}