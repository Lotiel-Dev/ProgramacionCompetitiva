#include <bits/stdc++.h>

using namespace std;

void resolver() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> pd(n + 2, 0);

    for (int i = n - 1; i >= 1; i--) {

        int ignorar = pd[i + 1];
        int salto = arr[i - 1];
        int sig_idx = i + salto + 1;

        int tomar = 0;
        bool es_salto_valido = (sig_idx <= n + 1);

        if (es_salto_valido) {
            tomar = 1 + salto + pd[sig_idx];
        }
        
        pd[i] = max(ignorar, tomar);
    }

    cout << n - pd[1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int casos = 1;
    cin >> casos;
    while (casos--) {
        resolver();
    }
    return 0;
}