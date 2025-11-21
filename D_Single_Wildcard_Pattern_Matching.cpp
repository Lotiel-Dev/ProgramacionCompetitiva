#include <bits/stdc++.h> 
using namespace std; 
#define ll  long long

int main(){
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if(n > m && n- m > 1){
          cout << "NO" << endl;
        return 0;
    }
    int i = 0 , j  = 0;
    for(; i< n;i++, j++){
        if(s[i] == '*'){
            break;
        }
        else{
            if(s[i]!= t[j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
     if(i == n and j == m){
        cout << "YES" << endl;
        return 0;
    }
   
    if(i == n and j!= m){
        cout << "NO" << endl;
        return 0;
    }
    int len1 = n- i- 1;
    int len2 = m-i;
    if(len1 > len2){
        cout << "NO" << endl;
        return 0;
    }
    j = m-len1;
    for(int k = i+1; k < n; k++,j++){
        if(s[k]!= t[j]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

}