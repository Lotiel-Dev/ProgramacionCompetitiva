#include <bits/stdc++.h>
using namespace std;

const int DESC = 0; 
const int COMP = 1; 
const int GYM = 2; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> act(n);
    for(int i = 0; i < n; i++) {
        cin >> act[i];
    }
    vector<vector<int>> pd(n, vector<int>(3, -1));

    auto calc_pd = [&](auto &&self, int dia, int act_prev) -> int {
        
        if(dia >= n) {
            return 0;
        }
        if(pd[dia][act_prev] != -1) {
            return pd[dia][act_prev];
        }

        int min_desc = 1 + self(self, dia + 1, DESC);

        bool puede_comp = (act[dia] == COMP || act[dia] == 3);
        bool evito_rep_comp = (act_prev != COMP);

        if(puede_comp && evito_rep_comp) {
            min_desc = min(min_desc, self(self, dia + 1, COMP));
        }

        bool puede_gym = (act[dia] == GYM || act[dia] == 3);
        bool evito_rep_gym = (act_prev != GYM);

        if(puede_gym && evito_rep_gym) {
            min_desc = min(min_desc, self(self, dia + 1, GYM));
        }
        return pd[dia][act_prev] = min_desc;
    };

    cout << calc_pd(calc_pd, 0, DESC) << "\n";
    
    return 0;
}