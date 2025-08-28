#include <iostream>
#include <string>
#include <bitset>
using namespace std;




string toBinary(long long n, int width) {
    string binary;               
    for (int i = width - 1; i >= 0; i--) {  
        binary += ((n >> i) & 1) ? '1' : '0';  
    }
    return binary;               
}

int main() {
    string val1;
    string val2;

    cin >> val1;
    cin >> val2;

    long long decimalVal1 = std::stoi(val1, nullptr, 2);
    long long decimalVal2 = std::stoi(val2, nullptr, 2);
    long long resultado = decimalVal1 ^ decimalVal2;

    
    cout << toBinary(resultado,val1.length()) << "\n";
    return 0;
}