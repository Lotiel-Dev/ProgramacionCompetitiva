#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> padre(n);
        for(int i = 1; i < n; i++) {
            cin >> padre[i];
            padre[i]--;
        }
        padre[0] = -1;
        
        set<int> malos;
        vector<set<int>> puntos(n);
        vector<int> peso(n);
        
        for(auto& i : peso) {
            cin >> i;
            i -= 1;
        }
        
        for(int i = 0; i < n; i++) {
            int j = peso[i];
            while(j != -1) {
                puntos[j].insert(i);
                j = padre[j];
            }
        }
        
        vector<int> id(n);
        for(int i = 0; i < n; i++) {
            id[peso[i]] = i;
        }
        
        for(int i = 0; i < n; i++) {
            if(*prev(puntos[i].end()) - *puntos[i].begin() != puntos[i].size() - 1 || *puntos[i].begin() != id[i]) {
                malos.insert(i);
            }
        }
        
        for(int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            
            id[peso[x]] = y;
            id[peso[y]] = x;
            
            int actual = peso[x];
            while(actual != -1) {
                puntos[actual].erase(x);
                actual = padre[actual];
            }
            
            actual = peso[y];
            while(actual != -1) {
                puntos[actual].erase(y);
                puntos[actual].insert(x);
                if(*prev(puntos[actual].end()) - *puntos[actual].begin() != puntos[actual].size() - 1 || *puntos[actual].begin() != id[actual]) {
                    malos.insert(actual);
                } else {
                    malos.erase(actual);
                }
                actual = padre[actual];
            }
            
            actual = peso[x];
            while(actual != -1) {
                puntos[actual].insert(y);
                if(*prev(puntos[actual].end()) - *puntos[actual].begin() != puntos[actual].size() - 1 || *puntos[actual].begin() != id[actual]) {
                    malos.insert(actual);
                } else {
                    malos.erase(actual);
                }
                actual = padre[actual];
            }
            
            swap(peso[x], peso[y]);
            
            if(malos.empty()) {
                cout << "YES";
            } else {
                cout << "NO";
            }
            cout << '\n';
        }
    }
    return 0;
}