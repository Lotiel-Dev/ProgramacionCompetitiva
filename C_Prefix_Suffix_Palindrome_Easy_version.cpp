#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if((int) s[i] < 97) s[i] = ((char)(s[i] ^ 32));
    }
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] ==  'a' || s[i] ==  'o' || s[i] ==  'y' || s[i] == 'e' || s[i] ==  'u' || s[i] ==  'i'){
            continue;
        }
        else {
            ans += '.';
            ans +=  s[i];
        }
    }

    cout << ans;
}