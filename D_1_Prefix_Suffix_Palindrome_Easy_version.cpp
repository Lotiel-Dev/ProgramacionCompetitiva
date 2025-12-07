#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    int l = 0;
    int r = n - 1;
    
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            break;
        }
    }
    
    if (l >= r) {
        cout << s << "\n";
        return;
    }
    
    string mid = s.substr(l, r - l + 1);
    
    string best_mid = "";
    
    for (int i = mid.length(); i >= 1; i--) {
        string sub = mid.substr(0, i);
        if (isPalindrome(sub)) {
            if (sub.length() > best_mid.length()) {
                best_mid = sub;
            }
            break;
        }
    }
    
    for (int i = mid.length(); i >= 1; i--) {
        string sub = mid.substr(mid.length() - i);
        if (isPalindrome(sub)) {
            if (sub.length() > best_mid.length()) {
                best_mid = sub;
            }
            break;
        }
    }
    
    string prefix_fixed = s.substr(0, l);
    string suffix_fixed = s.substr(r + 1); 
    
    cout << prefix_fixed << best_mid << suffix_fixed << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}