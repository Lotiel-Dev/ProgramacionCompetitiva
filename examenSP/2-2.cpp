#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge { int to, cap, rev; };
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;
    Dinic(int n): N(n), G(n), level(n), it(n) {}

    void add_edge(int u, int v, int c) {
        Edge a{v, c, (int)G[v].size()};
        Edge b{u, 0, (int)G[u].size()};
        G[u].push_back(a);
        G[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q; level[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : G[u]) if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                if (e.to == t) return true;
                q.push(e.to);
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u, int t, int f) {
        if (u == t) return f;
        for (int &i = it[u]; i < (int)G[u].size(); ++i) {
            Edge &e = G[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int ret = dfs(e.to, t, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    G[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0, inf = 1e9;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (int pushed = dfs(s, t, inf)) flow += pushed;
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<int> c(n+1);
    for (int i = 1; i <= n; ++i) cin >> c[i];

    // Nodos: 0=source, 1..m=clientes, m+1..m+n=platos, m+n+1=sink
    int S = 0, T = m + n + 1, V = T + 1;
    Dinic dinic(V);

    // Source -> clientes (cap 1)
    for (int i = 1; i <= m; ++i) dinic.add_edge(S, i, 1);

    // Platos -> sink (cap c_j)
    for (int j = 1; j <= n; ++j) dinic.add_edge(m + j, T, c[j]);

    // Preferencias: cliente i -> plato pj (cap 1)
    for (int i = 1; i <= m; ++i) {
        int k; cin >> k;
        for (int t = 0; t < k; ++t) {
            int pj; cin >> pj;
            if (1 <= pj && pj <= n)
                dinic.add_edge(i, m + pj, 1);
        }
    }

    cout << dinic.maxflow(S, T) << "\n";
    return 0;
}



//por si acaso este es de chatGPT free:///////////////////////////////

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, cap, rev;
};

struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;

    Dinic(int n) : N(n), G(n), level(n), it(n) {}

    void addEdge(int u, int v, int cap) {
        G[u].push_back({v, cap, (int)G[v].size()});
        G[v].push_back({u, 0, (int)G[u].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : G[u]) {
                if(level[e.v] < 0 && e.cap > 0) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] >= 0;
    }

    int sendFlow(int u, int t, int f) {
        if(u == t) return f;
        for(int &i = it[u]; i < (int)G[u].size(); i++) {
            Edge &e = G[u][i];
            if(level[e.v] == level[u] + 1 && e.cap > 0) {
                int pushed = sendFlow(e.v, t, min(f, e.cap));
                if(pushed > 0) {
                    e.cap -= pushed;
                    G[e.v][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while(bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (int pushed = sendFlow(s, t, INT_MAX))
                flow += pushed;
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    int S = 0;
    int T = n + m + 1;
    Dinic dinic(T + 1);

    // S -> clientes
    for(int i = 0; i < m; i++) {
        dinic.addEdge(S, 1 + i, 1);
    }

    // clientes -> platos
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while(k--) {
            int p;
            cin >> p;
            p--; // zero-based
            dinic.addEdge(1 + i, 1 + m + p, 1);
        }
    }

    // platos -> T
    for(int j = 0; j < n; j++) {
        dinic.addEdge(1 + m + j, T, c[j]);
    }

    cout << dinic.maxFlow(S, T) << "\n";

    return 0;
}
