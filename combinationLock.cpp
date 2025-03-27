/* 
https://codeforces.com/problemset/problem/2091/C
At the IT Campus "NEIMARK", there are several top-secret rooms where problems for major programming competitions are developed. To enter one of these rooms, you must unlock a circular lock by selecting the correct code. This code is updated every day.

Today's code is a permutation∗
 of the numbers from 1
 to n
, with the property that in every cyclic shift†
 of it, there is exactly one fixed point. That is, in every cyclic shift, there exists exactly one element whose value is equal to its position in the permutation.

Output any valid permutation that satisfies this condition. Keep in mind that a valid permutation might not exist, then output −1
.

∗
A permutation is defined as a sequence of length n
 consisting of integers from 1
 to n
, where each number appears exactly once. For example, (2 1 3), (1), (4 3 1 2) are permutations; (1 2 2), (3), (1 3 2 5) are not.

†
A cyclic shift of an array is obtained by moving the last element to the beginning of the array. A permutation of length n
 has exactly n
 cyclic shifts.
*/

#include <iostream>
#include <vector>

int main() {
    int testCases;
    std::cin >> testCases;

    std::vector<int> Casos(testCases);  // Vector para almacenar los valores

    for (int i = 0; i < testCases; ++i) {
        std::cin >> Casos[i];
    }

    for (int i = 0; i < testCases; i++){
        int valor = Casos[i];
        int aux = 1;
        if ((valor%2)==0){
            std::cout << -1;
        }else{
            for (int i = 0; i < valor; i++)
            {
                int ciclo = i+aux;
                if(ciclo <= valor){
                    std::cout << ciclo << " ";
                }else{
                    ciclo = ciclo - valor;
                    std::cout << ciclo << " ";
                }
                aux++;
            }      
        }
        std::cout << "\n" ;
        aux = 1; 
    }
    
    return 0;
}
