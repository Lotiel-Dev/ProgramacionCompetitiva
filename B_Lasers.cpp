#include <bits/stdc++.h>
using namespace std;

int main (){
    int testcases; cin >> testcases;

    while (testcases--)
    {
        int n,m,x,y,cont=0;
        cin >> n >> m >> x >> y;
        
        int ny,mx;


        for (int i = 0; i < n; i++)
        {
            cin >> ny;
            if (ny < y){
                cont++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            cin >> mx;
            if(mx < x){
                cont++;
            }
        }
        
        
        
        

        cout << cont << endl;
    }
    
}