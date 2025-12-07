#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long ix, iy, fx, fy;
        cin >> ix >> iy >> fx >> fy;

        long long sum = 0, may = 0, val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            sum += val;
            if (val > may) may = val;
        }

        long long dx = fx - ix;
        long long dy = fy - iy;
        long long d2 = dx * dx + dy * dy;

        long long min_d = (2 * may > sum) ? (2 * may - sum) : 0;

        if (sum * sum >= d2 && (min_d == 0 || min_d * min_d <= d2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
