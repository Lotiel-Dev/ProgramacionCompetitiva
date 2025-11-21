#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

unordered_map<string,int> mp;
vector<int> adj[MAXN + 5];
int est[MAXN + 5];
vector<int> pilaOrd, ordFinal;

inline bool bit(int ms, int b) {
    return ms & (1 << b);
}

void dfs(int u) {
    est[u] = 1;
    for (int v : adj[u]) {
        if (est[v] == 2) continue;
        if (est[v] == 1) {
            cout << "NO\n";
            exit(0);
        }
        dfs(v);
    }
    est[u] = 2;
    pilaOrd.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        string p;
        cin >> p;
        mp[p] = i;
    }

    for (int i = 1; i <= m; i++) {
        string t;
        int id;
        cin >> t >> id;

        bool ok = false;

        for (int ms = 0; ms < (1 << k); ms++) {
            string tmp;
            tmp.reserve(k);

            for (int j = 0; j < k; j++) {
                tmp.push_back(bit(ms, j) ? '_' : t[j]);
            }

            int x = mp[tmp];

            if (x == id) ok = true;
            if (x != 0 && x != id) adj[id].push_back(x);
        }

        if (!ok) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!est[i]) {
            pilaOrd.clear();
            dfs(i);
            for (int u : pilaOrd) ordFinal.push_back(u);
        }
    }

    reverse(ordFinal.begin(), ordFinal.end());

    cout << "YES\n";
    for (int u : ordFinal) cout << u << " ";
    cout << "\n";

    return 0;
}
