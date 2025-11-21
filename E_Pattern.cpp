#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    
    while (t--){
        int n;
        cin >> n;
        string s;
        vector<string> v;
        int len;

        for (int i = 1; i <= n; i++){
            cin >> s;
            len = s.length();
            v.push_back(s);
        }

        string ans = "";
        
        for (int j = 0; j < len; j++){
            set<char> st;
            for (int i = 0; i < n; i++){
                st.insert(v[i][j]);
            }
            if (st.size() >= 3){
                ans += '?';
            }
            else if (st.size() == 1){
                char c = *st.begin();
                if (c == '?'){
                    ans += 'a';
                }
                else{
                    ans += c;
                }
            }
            else{
                char c1 = *st.begin();
                char c2 = *st.rbegin();
                if (c1 == '?' || c2 == '?'){
                    if (c1 == '?'){
                        ans += c2;
                    }
                    else{
                        ans += c1;
                    }
                }
                else{
                    ans += '?';
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}