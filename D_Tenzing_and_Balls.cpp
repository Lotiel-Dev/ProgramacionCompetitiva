#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    
    int casos;
    cin >> casos;
    
    while(casos--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        vector<int> mejor(n + 1, 1e9);
        
        int act = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        for(int i = 0; i < n; i++) {
            int act_prev = act;
            act = min(act + 1, mejor[arr[i]]);
            mejor[arr[i]] = min(mejor[arr[i]], act_prev);
        }
        
        cout << n - act << "\n";
    }
    return 0;
}