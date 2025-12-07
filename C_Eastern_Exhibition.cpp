#include <bits/stdc++.h>
using namespace std;

void solucion() {
    long long n;
    cin >> n;
    vector<long long> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long dif_x = x[n / 2] - x[(n - 1) / 2] + 1;
    long long dif_y = y[n / 2] - y[(n - 1) / 2] + 1;

    cout << dif_x * dif_y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solucion();
    }
    return 0;
}