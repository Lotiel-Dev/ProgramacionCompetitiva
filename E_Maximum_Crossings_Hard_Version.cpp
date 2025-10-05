#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, MK; 
    cin >> t;
    while(t--){
        long long n, rx = 0;
        cin >> n;
        vector<int> a(n), T(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = n - 1; i >= 0; i--){
            for(int x = a[i]; x > 0; x -= x & -x){
                rx += T[x];
            }
            for(int x = a[i]; x <= n; x += x & -x){
                T[x] += 1;
            }
        }
        cout << rx << '\n';
    }
    return 0;
}