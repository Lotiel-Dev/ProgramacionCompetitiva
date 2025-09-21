#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout<<#x<<": "<< x <<"\n";

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a[i]={x,i+1};
    }

    if(n == 2){
        cout<< "1\n"; return;
    }
    
    sort(a.begin() , a.end());
    int pos_r=a[2].first-a[1].first;
    int k=0;
    int from=3;
    for(int rep=0 ; rep<2 ; rep++){
        debug1(pos_r)
        // dont use the formula, use the distance
        int factor=2;
        bool ok=true;
        for(int i=from ; i<n ; i++){
            // start value for i is bad, then it should be ok
            int tmp=a[i].first + (pos_r*factor);
            if(tmp == a[i].first) factor++;
            else{
                ok=false;
                break;
            }
        }
        if(ok){
            cout<< a[k].second <<"\n"; return;
        }
        pos_r=a[2].first-a[0].first;
        k=1;
    }
    pos_r=a[1].first-a[0].first;
    int factor=2;
    int ans=-1;
    for(int i=2 ; i<n ; i++){
        int tmp=a[0].first+(pos_r*factor);
        //debug1(a[i].first)
        //debug1(tmp)
        if(tmp == a[i].first) factor++;
        else if(ans == -1){
            ans=a[i].second;
        }else{
            cout<<"-1\n"; return;
        }
    }
    cout<< ans <<"\n";
}

int main(){
    solve();
}