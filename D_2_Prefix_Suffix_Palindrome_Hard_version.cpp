#include <bits/stdc++.h>
using namespace std;

vector<int> compute_pi(const string &s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string get_longest_pal_prefix(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    string temp = s + "#" + rev_s;
    
    vector<int> pi = compute_pi(temp);
    int len = pi.back();
    
    return s.substr(0, len);
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
    string pal_prefix = get_longest_pal_prefix(mid);
    
    string rev_mid = mid;
    reverse(rev_mid.begin(), rev_mid.end());
    string pal_suffix = get_longest_pal_prefix(rev_mid);
    
    string prefix_fixed = s.substr(0, l);
    string suffix_fixed = s.substr(r + 1);
    
    if (pal_prefix.length() >= pal_suffix.length()) {
        cout << prefix_fixed << pal_prefix << suffix_fixed << "\n";
    } else {
        cout << prefix_fixed << pal_suffix << suffix_fixed << "\n";
    }
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