#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        mp[val]++;
    }

    vector<int> res;
    for (auto it : mp) {
        int cant = it.second / 2;
        while (cant--) {
            res.push_back(it.first);
        }
    }

    if (res.size() < 4) {
        cout << "NO\n";
        return;
    }

    int tam = res.size();
    int v1 = res[0];
    int v2 = res[1];
    int v4 = res[tam - 1];
    int v3 = res[tam - 2];

    cout << "YES\n";
    cout << v1 << " " << v2 << " " << v1 << " " << v4 << " " << v3 << " " << v2 << " " << v3 << " " << v4 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}