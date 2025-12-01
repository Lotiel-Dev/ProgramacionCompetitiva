#include <bits/stdc++.h>

using namespace std;
bool es_posible(int n, int k_ops, const string& s, const string& t, 
                const vector<vector<int>>& posiciones_char, vector<int>& target_src) {
    
    int max_dist = k_ops; 
    int ultimo_idx = 0;
    target_src.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        int char_code = t[i] - 'a';
        const vector<int>& indices = posiciones_char[char_code];
        
        
        int min_p_necesario = max(ultimo_idx, i - max_dist);
        
        auto it = lower_bound(indices.begin(), indices.end(), min_p_necesario);
        
        if (it == indices.end() || *it > i) {
            return false;
        }
        
        ultimo_idx = *it;
        target_src[i] = ultimo_idx;
    }
    return true;
}

void resolver() {
    int n, k_max;
    if (!(cin >> n >> k_max)) return;
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << "\n";
        return;
    }
    
    if (s[0] != t[0]) {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> posiciones_char(26);
    for (int i = 0; i < n; ++i) {
        posiciones_char[s[i] - 'a'].push_back(i);
    }

    int bajo = 1, alto = k_max;
    int ans_k = -1;
    vector<int> final_target_src; 
    vector<int> temp_target_src;

    while (bajo <= alto) {
        int mid = bajo + (alto - bajo) / 2;
        if (es_posible(n, mid, s, t, posiciones_char, temp_target_src)) {
            ans_k = mid;
            final_target_src = temp_target_src;
            alto = mid - 1; 
        } else {
            bajo = mid + 1; 
        }
    }

    if (ans_k == -1) {
        cout << -1 << "\n";
        return;
    }

    cout << ans_k << "\n";

    vector<int> indices_actuales(n);
    for(int i=0; i<n; ++i) indices_actuales[i] = i;

    for (int paso = 1; paso <= ans_k; ++paso) {
        vector<int> siguientes_indices(n);
        string string_paso = "";
        
        siguientes_indices[0] = 0;
        string_paso += s[siguientes_indices[0]];

        for (int i = 1; i < n; ++i) {
            int opcion_mover = indices_actuales[i-1];
            
            if (opcion_mover >= final_target_src[i]) {
                siguientes_indices[i] = opcion_mover;
            } else {
                siguientes_indices[i] = indices_actuales[i];
            }
            string_paso += s[siguientes_indices[i]];
        }
        
        indices_actuales = siguientes_indices;
        cout << string_paso << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            resolver();
        }
    }
    return 0;
}