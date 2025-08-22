//https://codeforces.com/contest/136/problem/A
#include <iostream>
#include <vector>

int main() {
    int Casos;
    std::cin >> Casos;
    std::vector<int> regalos(Casos);
    std::vector<int> orden(Casos);
    
    for (int i = 0; i < Casos; i++){
        std::cin >> regalos[i];
        orden[regalos[i]-1] = (i+1);           
    }

    for(int c : orden){
        
        std::cout << c << " ";
    }
    std::cout << "\n" ;
    return 0;
}