#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const char nl = '\n';

const int N = 2e5;
int arr[N];
void resolver() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ult_val = arr[0];
    int resp = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > ult_val + 1) {
            ult_val = arr[i];
            resp++;
        }
    }
    
    cout << resp << nl;
}

int main() {
    // Optimización de entrada/salida
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int casos = 1;
    cin >> casos;
    while (casos--) {
        resolver();
    }
}