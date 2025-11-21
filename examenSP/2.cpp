#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int to, capacity, flow, rev;
};

class MaxFlow {
private:
    int n;
    vector<vector<Edge>> graph;
    vector<int> level, iter;
    
public:
    MaxFlow(int size) {
        n = size;
        graph.resize(n);
        level.resize(n);
        iter.resize(n);
    }
    
    void addEdge(int from, int to, int capacity) {
        graph[from].push_back({to, capacity, 0, (int)graph[to].size()});
        graph[to].push_back({from, 0, 0, (int)graph[from].size() - 1});
    }
    
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (const Edge& e : graph[u]) {
                if (e.capacity > e.flow && level[e.to] < 0) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    
    int dfs(int u, int t, int f) {
        if (u == t) return f;
        
        for (int& i = iter[u]; i < graph[u].size(); i++) {
            Edge& e = graph[u][i];
            
            if (e.capacity > e.flow && level[u] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.capacity - e.flow));
                if (d > 0) {
                    e.flow += d;
                    graph[e.to][e.rev].flow -= d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    int maxFlow(int s, int t) {
        int flow = 0;
        
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            
            int f;
            while ((f = dfs(s, t, INT_MAX)) > 0) {
                flow += f;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> capacidades(n);
    for (int i = 0; i < n; i++) {
        cin >> capacidades[i];
    }
    
    // Nodos: 0 (fuente), 1..n (platos), n+1..n+m (clientes), n+m+1 (sumidero)
    int total_nodos = n + m + 2;
    MaxFlow flow(total_nodos);
    
    int fuente = 0;
    int sumidero = n + m + 1;
    
    // Conectar fuente a platos
    for (int i = 0; i < n; i++) {
        flow.addEdge(fuente, i + 1, capacidades[i]);
    }
    
    // Leer preferencias de clientes y conectar platos a clientes
    for (int cliente = 0; cliente < m; cliente++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int plato;
            cin >> plato;
            flow.addEdge(plato, n + 1 + cliente, 1);
        }
    }
    
    // Conectar clientes a sumidero
    for (int cliente = 0; cliente < m; cliente++) {
        flow.addEdge(n + 1 + cliente, sumidero, 1);
    }
    
    // Calcular flujo máximo
    int resultado = flow.maxFlow(fuente, sumidero);
    cout << resultado << endl;
    
    return 0;
}