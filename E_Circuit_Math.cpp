///paso las pruebas
#include <bits/stdc++.h>
using namespace std;

bool toBool(char c) {
    return c == 'T';
}

char toChar(bool b) {
    return b ? 'T' : 'F';
}

int main() {
    int n;
    cin >> n;
    vector<bool> values(26, false);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        values[i] = toBool(c);
    }
    
    string circuit;
    cin.ignore(); 
    getline(cin, circuit);
    
    stack<bool> st;
    for (char c : circuit) {
        if (c == ' ') continue;
        if (c >= 'A' && c <= 'Z') {
            int index = c - 'A';
            st.push(values[index]);
        } else if (c == '*' || c == '+' || c == '-') {
            if (c == '*') {
                bool op2 = st.top(); st.pop();
                bool op1 = st.top(); st.pop();
                st.push(op1 && op2);
            } else if (c == '+') {
                bool op2 = st.top(); st.pop();
                bool op1 = st.top(); st.pop();
                st.push(op1 || op2);
            } else if (c == '-') {
                bool op = st.top(); st.pop();
                st.push(!op);
            }
        }
    }
    
    cout << toChar(st.top()) << endl;
    
    return 0;
}