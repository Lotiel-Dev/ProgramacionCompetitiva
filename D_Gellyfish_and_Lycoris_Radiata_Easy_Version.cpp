///no supera el time limitid

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> conjuntos(n+1);
    int ans_anterior = 0;
    
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int r, x, p;
        
        if (a == 1) {
            r = (b + ans_anterior - 1) % n + 1;
            for (int j=1; j<=r; j++) {
                conjuntos[j].insert(i);
            }
        } else if (a == 2) {
            r = (b + ans_anterior - 1) % n + 1;
            reverse(conjuntos.begin()+1, conjuntos.begin()+r+1);
        } else if (a == 3) {
            x = (b + ans_anterior - 1) % q + 1;
            for (int j=1; j<=n; j++) {
                conjuntos[j].erase(x);
            }
        }
        
        p = (c + ans_anterior - 1) % n + 1;
        if (conjuntos[p].empty()) {
            ans_anterior = 0;
        } else {
            ans_anterior = *conjuntos[p].begin();
        }
        cout << ans_anterior << endl;
    }
    
    return 0;
}