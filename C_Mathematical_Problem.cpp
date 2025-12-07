#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return;
    }

    int lim = (n - 3) / 2;

    for (int i = 0; i <= lim; i++) {
        cout << "1";
        for (int j = 0; j < i; j++) {
            cout << "0";
        }
        cout << "6";
        for (int j = 0; j < i; j++) {
            cout << "0";
        }
        cout << "9";
        for (int j = 0; j < n - 3 - 2 * i; j++) {
            cout << "0";
        }
        cout << "\n";
    }

    for (int i = 0; i <= lim; i++) {
        cout << "9";
        for (int j = 0; j < i; j++) {
            cout << "0";
        }
        cout << "6";
        for (int j = 0; j < i; j++) {
            cout << "0";
        }
        cout << "1";
        for (int j = 0; j < n - 3 - 2 * i; j++) {
            cout << "0";
        }
        cout << "\n";
    }

    cout << "196";
    for (int i = 0; i < n - 3; i++) {
        cout << "0";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}