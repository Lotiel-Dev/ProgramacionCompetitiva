#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    string L;
    cin>>L;

    int wantStart = (L[1]=='X'?0:1);
    int wantEnd   = (L[0]=='X'?0:1);

    int cnt[4]={0};
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]=="XX") cnt[0]++;
        else if(v[i]=="XY") cnt[1]++;
        else if(v[i]=="YX") cnt[2]++;
        else cnt[3]++;
    }

    // dp[usados_totales][lado_final] = mapa { (u0,u1,u2,u3) → formas }
    unordered_map<long long,long long> dp[41][2];

    auto pack=[&](int a,int b,int c,int d){
        return ((long long)a<<24)|((long long)b<<16)|((long long)c<<8)|d;
    };

    dp[0][wantStart][ pack(0,0,0,0) ] = 1;

    for(int used=0; used<k; used++){
        for(int last=0; last<2; last++){
            for(auto &pr: dp[used][last]){
                long long key=pr.first;
                long long ways=pr.second;

                int a=(key>>24)&255;
                int b=(key>>16)&255;
                int c=(key>>8 )&255;
                int d=(key    )&255;

                if(last==0){
                    if(a<cnt[0]) dp[used+1][0][ pack(a+1,b,c,d) ]+=ways;
                    if(b<cnt[1]) dp[used+1][1][ pack(a,b+1,c,d) ]+=ways;
                }else{
                    if(c<cnt[2]) dp[used+1][0][ pack(a,b,c+1,d) ]+=ways;
                    if(d<cnt[3]) dp[used+1][1][ pack(a,b,c,d+1) ]+=ways;
                }
            }
        }
    }

    long long ans=0;
    for(auto &p: dp[k][wantEnd])
        ans+=p.second;

    cout<<ans<<"\n";
}
