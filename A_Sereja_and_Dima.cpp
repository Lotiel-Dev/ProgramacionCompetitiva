//falta terminar
#include <bits/stdc++.h>
using namespace std;

int main(){
    int maso;
    int sereja=0;
    int dima=0;
    cin >> maso;
    bool turno=true;
    deque<int> cartas;

    for (int i = 0; i < maso; i++){
        int x; cin >> x;
        cartas.push_back(x);
    }

    while(!cartas.empty()){
        int x=cartas.front() , y=cartas.back();
    
        if (cartas.size() == 1 )
        {
            sereja += x;
            break;
        }
        
        if (x < y)
        {
            if (turno){
                sereja += x;
                //cartas.erase(cartas.begin());
                cartas.pop_front();
            }else{
                dima += y;
                //cartas.erase(cartas.begin());
                cartas.pop_back();
            }
            turno=!turno;
        }else{
            if (turno){
                sereja += x;
            
                cartas.pop_front();
            }else{
                dima += y;
                cartas.pop_back();
                //cartas.pop_back();
            }
            turno = !turno;
        }
        
    }
    
    cout << dima << " " << sereja << "\n";

    
}