#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (ll)4e18;
const int NMAX = 200000;

ll a[NMAX+5], b[NMAX+5];
ll sumextra[NMAX+5];

ll seg[4*NMAX+5];
ll lazyv[4*NMAX+5];

void aplicar_lazy(int nd, int l, int r) {
    if (lazyv[nd] != 0) {
        seg[nd] += lazyv[nd];
        if (l != r) {
            lazyv[nd*2]     += lazyv[nd];
            lazyv[nd*2 + 1] += lazyv[nd];
        }
        lazyv[nd] = 0;
    }
}


void upd(int nd, int l, int r, int ql, int qr, ll val) {
    aplicar_lazy(nd, l, r);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        lazyv[nd] += val;
        aplicar_lazy(nd, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(nd*2, l, mid, ql, qr, val);
    upd(nd*2+1, mid+1, r, ql, qr, val);
    seg[nd] = min(seg[nd*2], seg[nd*2+1]);
}

ll qry(int nd, int l, int r, int ql, int qr) {
    aplicar_lazy(nd, l, r);
    if (qr < l || r < ql) return INF;
    if (ql <= l && r <= qr) return seg[nd];
    int mid = (l + r) / 2;
    return min(
        qry(nd*2, l, mid, ql, qr),
        qry(nd*2+1, mid+1, r, ql, qr)
    );
}


struct E { int x, y, c; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i < n; i++)
        cin >> a[i] >> b[i];

    vector<E> ve(m);
    for (int i = 0; i < m; i++)
        cin >> ve[i].x >> ve[i].y >> ve[i].c;

    sort(ve.begin(), ve.end(),
        [](const E& A, const E& B) { return A.x < B.x; });

    for (int i = 1; i <= n; i++)
        upd(1, 1, n, i, i, b[i]);

    for (auto &ed : ve) {
        int lx = ed.x;
        int ly = ed.y;
        int cap = ed.c;

        if (ly == n) {
            sumextra[lx] += cap;
        } else {
            ll mn = qry(1, 1, n, ly, n-1);
            ll usar = min(mn, (ll)cap);
            sumextra[lx] += usar;
            upd(1, 1, n, ly, n-1, -usar);
        }
    }

    for (int i = 1; i <= n; i++)
        sumextra[i] += sumextra[i-1];

    multiset<ll> ms;
    for (int i = 1; i <= n; i++)
        ms.insert(a[i] + sumextra[i]);

    cout << *ms.begin() << "\n";

    while (q--) {
        int p, val;
        cin >> p >> val;

        ms.erase(ms.find(a[p] + sumextra[p]));
        a[p] = val;
        ms.insert(a[p] + sumextra[p]);

        cout << *ms.begin() << "\n";
    }

    return 0;
}
