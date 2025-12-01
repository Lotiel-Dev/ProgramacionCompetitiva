#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> cadenas(n);
    for (auto &s : cadenas) {
        cin >> s;
    }

    string objetivo;
    cin >> objetivo;

    int mejorPrefijo = 0;
    vector<string> resto(objetivo.size() + 1);

    for (const auto &cad : cadenas) {
        int pos = 0;
        for (char c : cad) {
            if (pos < (int)objetivo.size() && objetivo[pos] == c) {
                pos++;
            } else {
                resto[pos] += c;
            }
        }
        mejorPrefijo = max(mejorPrefijo, pos);
    }

    if (mejorPrefijo == (int)objetivo.size()) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for (int i = 0; i < (int)objetivo.size(); i++) {
        cout << resto[i];
        if (i < mejorPrefijo)
            cout << objetivo[i];
    }

    return 0;
}
