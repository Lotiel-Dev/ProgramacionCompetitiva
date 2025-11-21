#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[4];        // cantidad por tipo
int st, en;      // start, end
string loco;
vector<string> v;

unordered_map<uint64_t, long long> dp;

// Empaque de estado en un entero de 64 bits
static inline uint64_t mk(int a, int b, int c, int d, int s) {
    return (((((uint64_t)a << 6) | b) << 6 | c) << 6 | d) << 1 | s;
}

long long go(int a, int b, int c2, int d, int side) {
    int tot = a + b + c2 + d;
    if (tot == k) return (side == en);

    uint64_t key = mk(a,b,c2,d,side);
    auto it = dp.find(key);
    if (it != dp.end()) return it->second;

    long long r = 0;

    if (side == 0) {
        if (a < c[0]) r += go(a+1, b, c2, d, 0);
        if (b < c[1]) r += go(a, b+1, c2, d, 1);
    } else {
        if (c2 < c[2]) r += go(a, b, c2+1, d, 0);
        if (d < c[3]) r += go(a, b, c2, d+1, 1);
    }

    dp[key] = r;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> loco;

    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    memset(c, 0, sizeof(c));

    for (auto &s : v) {
        if (s == "XX") c[0]++;
        else if (s == "XY") c[1]++;
        else if (s == "YX") c[2]++;
        else c[3]++;
    }

    st = (loco[1] == 'X') ? 0 : 1;
    en = (loco[0] == 'X') ? 0 : 1;

    cout << go(0,0,0,0,st) << "\n";
    return 0;
}

