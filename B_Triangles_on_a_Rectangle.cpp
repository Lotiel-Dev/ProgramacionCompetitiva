#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long an, al;
        cin >> an >> al;

        int cant;

        cin >> cant;
        vector<long long> v1(cant);
        for (int i = 0; i < cant; i++) {
            cin >> v1[i];
        }

        cin >> cant;
        vector<long long> v2(cant);
        for (int i = 0; i < cant; i++) {
            cin >> v2[i];
        }

        cin >> cant;
        vector<long long> v3(cant);
        for (int i = 0; i < cant; i++) {
            cin >> v3[i];
        }

        cin >> cant;
        vector<long long> v4(cant);
        for (int i = 0; i < cant; i++) {
            cin >> v4[i];
        }

        long long dif_h = max(v1.back() - v1[0], v2.back() - v2[0]);
        long long dif_v = max(v3.back() - v3[0], v4.back() - v4[0]);

        long long res = max(dif_h * al, dif_v * an);
        cout << res << "\n";
    }
    return 0;
}