#include <bits/stdc++.h>
using namespace std;

struct FlujoMax {
    struct Ar { int to; int rev; long long cap; };
    int nn;
    vector<vector<Ar>> G;
    vector<int> nivel, it;

    FlujoMax(int n = 0) : nn(n), G(n), nivel(n), it(n) {}

    void agregar_arista_dir(int a, int b, long long c) {
        Ar fa{b, (int)G[b].size(), c};
        Ar fb{a, (int)G[a].size(), 0};
        G[a].push_back(fa);
        G[b].push_back(fb);
    }

    bool construir_nivel(int s, int t) {
        fill(nivel.begin(), nivel.end(), -1);
        queue<int> q;
        nivel[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const Ar &ar : G[u]) {
                if (ar.cap > 0 && nivel[ar.to] == -1) {
                    nivel[ar.to] = nivel[u] + 1;
                    q.push(ar.to);
                }
            }
        }
        return nivel[t] != -1;
    }

    long long enviar(int u, int t, long long f) {
        if (u == t) return f;
        for (int &i = it[u]; i < (int)G[u].size(); ++i) {
            Ar &ar = G[u][i];
            if (ar.cap > 0 && nivel[ar.to] == nivel[u] + 1) {
                long long emp = enviar(ar.to, t, min(f, ar.cap));
                if (emp > 0) {
                    ar.cap -= emp;
                    G[ar.to][ar.rev].cap += emp;
                    return emp;
                }
            }
        }
        return 0;
    }

    long long max_flujo(int s, int t) {
        long long flujo = 0;
        const long long INF = (long long)4e18;
        while (construir_nivel(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (true) {
                long long emp = enviar(s, t, INF);
                if (emp == 0) break;
                flujo += emp;
            }
        }
        return flujo;
    }

    vector<char> corte_fuente(int s) {
        vector<char> vis(nn, 0);
        queue<int> q;
        vis[s] = 1; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const Ar &ar : G[u]) {
                if (ar.cap > 0 && !vis[ar.to]) {
                    vis[ar.to] = 1;
                    q.push(ar.to);
                }
            }
        }
        return vis;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int CAP_GRANDE = 1000000000;

    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) return 0;
    --s; --t;

    vector<int> A(m), B(m), was(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i] >> B[i] >> was[i];
        --A[i]; --B[i];
    }

    FlujoMax F1(n);
    for (int i = 0; i < m; ++i) {
        if (was[i] == 0) {
            F1.agregar_arista_dir(A[i], B[i], CAP_GRANDE);
        } else {
            F1.agregar_arista_dir(A[i], B[i], 1);
            F1.agregar_arista_dir(B[i], A[i], CAP_GRANDE);
        }
    }

    long long val_min_cut = F1.max_flujo(s, t);
    vector<char> en_fuente = F1.corte_fuente(s);
    cout << val_min_cut << "\n";

    int ss = n, tt = n + 1;
    FlujoMax F2(n + 2);

    struct Ref { int u; int idx; };
    vector<Ref> ref_orig(m, {-1, -1});

    for (int i = 0; i < m; ++i) {
        if (was[i] == 1) {
            F2.agregar_arista_dir(ss, B[i], 1);
            F2.agregar_arista_dir(A[i], tt, 1);

            long long cap = (long long)CAP_GRANDE - 2;
            if (cap < 0) cap = 0;

            int idx_adj = (int)F2.G[A[i]].size();
            F2.agregar_arista_dir(A[i], B[i], cap);
            ref_orig[i] = {A[i], idx_adj};
        }
    }

    F2.agregar_arista_dir(t, s, CAP_GRANDE);
    F2.max_flujo(ss, tt);

    vector<long long> flujo_res(m, 0), cap_res(m, 0);
    for (int i = 0; i < m; ++i) {
        if (was[i] == 0) {
            flujo_res[i] = 0;
            cap_res[i] = CAP_GRANDE;
        } else {
            long long flujo_extra = 0;
            if (ref_orig[i].u != -1) {
                int u = ref_orig[i].u;
                int idx = ref_orig[i].idx;
                auto e = F2.G[u][idx];
                int v = e.to;
                int rev = e.rev;
                flujo_extra = F2.G[v][rev].cap;
            }
            long long flujo_total = 1 + flujo_extra;
            flujo_res[i] = flujo_total;

            if (en_fuente[A[i]] && !en_fuente[B[i]]) {
                cap_res[i] = flujo_res[i];
            } else {
                cap_res[i] = CAP_GRANDE;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (cap_res[i] < 1) cap_res[i] = 1;
        if (cap_res[i] > CAP_GRANDE) cap_res[i] = CAP_GRANDE;
        if (flujo_res[i] < 0) flujo_res[i] = 0;
        if (flujo_res[i] > cap_res[i]) flujo_res[i] = cap_res[i];
    }

    for (int i = 0; i < m; ++i) {
        cout << flujo_res[i] << " " << cap_res[i] << "\n";
    }

    return 0;
}
