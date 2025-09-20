#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < n; i++) {
        // Eliminar índices fuera de la ventana
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Eliminar valores más pequeños que arr[i]
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        // El máximo está en dq.front()
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
    return 0;
}
