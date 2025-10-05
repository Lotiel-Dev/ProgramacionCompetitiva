#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;
    unordered_map<ll,ll> mp, mp1;
    vector<ll> v(n);
    for (auto &x : v){
        cin >> x;
        mp[x]++;
    }
    ll x = 0;
    for (auto x : mp){
        if (x.second % k){
            cout << 0 << endl;
            return;
        }
    }
    queue<ll> q;
    ll i = 0, j = 0;
    ll cnt = 0;
    while (j < n){
        mp1[v[j]]++;
        while (mp1[v[j]] > mp[v[j]] / k){
            cnt += q.size();
            mp1[v[i]]--;
            i++;
            q.pop();
        }
        q.push(v[j]);
        j++;
    }
    while (!q.empty()){
        cnt += q.size();
        q.pop();
    }
    cout << cnt << endl;
}

int main()
{
    ll test;
    cin >> test;
    while (test--){
        solve();
    }
    return 0;
}