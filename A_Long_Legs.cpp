#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main() {
	int t=1;
	cin>>t;
	while(t--) {
		ll a,b;
		cin>>a>>b;
		ll ans=a+b;
		for(ll m=1;m-1<ans;m++) {
			ans=min(ans, (a+m-1)/m + (b+m-1)/m + (m-1));
		}
		cout<<ans<<"\n";
	}	
	return 0;
}
