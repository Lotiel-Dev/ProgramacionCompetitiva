// /// EL MAS BONITO
// #include<bits/stdc++.h>
// using namespace std;
// int n,k,c,d;
// typedef long long ll;
// ll cal(vector<int>&a,int k){
// 	map<int,int>cnt;
// 	int l=0,r=0;
// 	ll res=0;
// 	while(l<=r&&r<n){
// 		cnt[a[r]]++;
// 		while(cnt.size()>k&&l<=r){
// 			cnt[a[l]]--;
// 			if(!cnt[a[l]])  cnt.erase(a[l]);
// 			l++;
// 		}
// 		int len=r-l+1;
// 		res+=max(0,min(d,len)-c+1);
// 		r++;
// 	}
// 	return res;
// }
// void solve(){
// 	cin>>n>>k>>c>>d;
// 	vector<int>a(n,0);
// 	for(int i=0;i<n;i++)  cin>>a[i];
// 	ll ans=cal(a,k)-cal(a,k-1);
// 	cout<<ans<<endl;
// }
// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--)  solve();
// 	return 0;
// }




//////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calcular_subarreglos(vector<int>& arr, int n, int k, int c, int d) {
    map<int, int> contador;
    int left = 0;
    ll total = 0;
    
    for (int right = 0; right < n; right++) {
        contador[arr[right]]++;
        
        while (contador.size() > k && left <= right) {
            contador[arr[left]]--;
            if (contador[arr[left]] == 0) {
                contador.erase(arr[left]);
            }
            left++;
        }
        
        int len = right - left + 1;
        if (len >= c) {
            int max_efectivo = min(d, len);
            total += (max_efectivo - c + 1);
        }
    }
    
    return total;
}

void solve() {
    int n, k, c, d;
    cin >> n >> k >> c >> d;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll con_k = calcular_subarreglos(arr, n, k, c, d);
    ll con_k_menos = calcular_subarreglos(arr, n, k - 1, c, d);
    
    ll resultado = con_k - con_k_menos;
    cout << resultado << endl;
}

int main() {
    int test;
    cin >> test;
    
    while (test--) {
        solve();
    }
    
    return 0;
}
