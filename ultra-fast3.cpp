#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int len = max(a.length(), b.length());
    
    
    for (int i = 0; i < len; i++) {
        cout << (a[i] != b[i] ? '1' : '0');
    }
    cout << "\n";
    
    return 0;
}