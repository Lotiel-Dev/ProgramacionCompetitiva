//https://codeforces.com/contest/2138/problem/E2

// Author: YE Minghan // https://codeforces.com/contest/2138/submission/337885773
#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
//#include "templates/debug.h"
#else
#define dbg(...) (void)0
#define here (void)0
#endif
using ll=long long;
using VI=vector<int>;
using PII=pair<int,int>;
#define endl '\n'
#define PB emplace_back
#define PPB pop_back
#define MP make_pair
#define ALL(Name) Name.begin(),Name.end()
#define GI greater<int>
#define fi first
#define se second
 
const int S=88;
mt19937 R(0x6eca11);
int a[S][S];
 
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int _;cin>>_;while(_--){
        int n;
        // n=N;
        cin>>n;
        if(n==0){cout<<"1\n0\n";continue;}
        if(n==1){cout<<"1\n1\n";continue;}
        uniform_int_distribution<int> F(n/3,n*2/3);
        while(1)
        {
            int p=n,q=F(R);
            while(__gcd(p,q)>1)q++;
            int l=0;
            while((q>1||p>1)&&l<50)
            {
                l++;
                a[l][l]=a[l][l+1]=1;
                a[l+1][l]=p>=q?-1:1;
                p=exchange(q,abs(p-q));
            }
            ++l;
            if(l<=50)
            {
                cout<<l<<endl;
                a[l][l]=1;
                for(int i=1;i<=l;i++)
                    for(int j=1;j<=l;j++)cout<<a[i][j]<<" \n"[j==l];
                break;
            }
        }
    }
 
	return 0;
}

/////////////////////////////////////SIN DEFINES///////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using PII = pair<int, int>;
#define endl '\n'
 
const int S=55;
mt19937 R(0x6eca11);
int a[S][S];
 
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int _;cin>>_;while(_--){
        int n;
        cin>>n;
        if(n==0){cout<<"1\n0\n";continue;}
        if(n==1){cout<<"1\n1\n";continue;}
        uniform_int_distribution<int> F(n/3,n*2/3);
        while(1)
        {
            int p=n,q=F(R);
            while(__gcd(p,q)>1)q++;
            int l=0;
            while((q>1||p>1)&&l<50)
            {
                l++;
                a[l][l]=a[l][l+1]=1;
                a[l+1][l]=p>=q?-1:1;
                p=exchange(q,abs(p-q));
            }
            l++;
            if(l<=50)
            {
                cout<<l<<endl;
                a[l][l]=1;
                for(int i=1;i<=l;i++)
                    for(int j=1;j<=l;j++)cout<<a[i][j]<<" \n"[j==l];
                break;
            }
        }
    }
 
	return 0;
}

//////////////////////////////////Alternativas ///////////////////////////////////////////////////////////////////


////////////////////////////////// BONITO ... /////////////////////////////////////////////////////////////////////
// https://codeforces.com/contest/2138/submission/337899191
#include<bits/stdc++.h>
using namespace std;
const double phi=((1+sqrt(5))/2);
int f[55],len=0,x;
// a=k1b+k2c
// c=k2a-k1k2b
bool check(int y){
    f[1]=x,f[2]=y;
    len=3;
    while(len<=52){
        f[len]=abs(abs(f[len-1])-abs(f[len-2]));
        if(f[len]==0 && f[len-1]==1)return true;
        len++;
    }
    return false;
}
int ans[55][55];
int main(){
    int Tc;
    scanf("%d",&Tc);
    while(Tc--){
        scanf("%d",&x);
        int y=x/phi;
        int d=0;
        while(1){
            if(check(y-d))break;
            if(check(y+d))break;
            d++;
        }
        int m=len-2;
        printf("%d\n",m);
        // for(int i=1;i<=m+2;i++)printf("%d ",f[i]);
        // printf("\n");
        for(int i=1;i<=m;i++){
            int f1,f2;
            for(int k1=-1;k1<=1;k1+=2)for(int k2=-1;k2<=1;k2+=2)if(k1*f[i+1]+k2*f[i+2]==f[i])f1=k1,f2=k2;
            ans[m-i+1][m-i+1]=f1;
            ans[m-i][m-i+1]=1;
            ans[m-i+1][m-i]=-f2;   
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++)printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}


///////////////////////////////////////////// mehhhh ////////////////////////////////////////////////////////////

// coached by rainboy  https://codeforces.com/contest/2138/submission/338540225
#include <algorithm>
#include <iostream>
#include <cmath>
 
using namespace std;
 
const int K = 64;
 
bool swapped[K];
 
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
 
int count(int a, int b) {
	if (a < b)
		swap(a, b);
	int n = 2;
	while (a > 1) {
		n++;
		int c = a - b;
		a = b, b = c;
		if (a < b)
			n++, swap(a, b);
	}
	return n;
}
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		if (x <= 1) {
			cout << "1\n";
			cout << x << '\n';
			continue;
		}
		int a_ = (int) x / ((1 + sqrt(5)) / 2 + 1), a = a_;
		while (gcd(a, x - a) > 1 || count(a, x - a) > 50)
			a = a_ * 2 - a + (a <= a_);
		int b = x - a;
		if (a < b)
			swap(a, b);
		int k = 0, n = 2;
		while (a > 1) {
			n++;
			int c = a - b;
			a = b, b = c;
			if (a < b)
				swapped[k++] = true, n++, swap(a, b);
			else
				swapped[k++] = false;
		}
		cout << n << '\n';
		for (int j_ = 0, h = k - 1; h >= 0; h--) {
			if (swapped[h]) {
				for (int j = 0; j < j_; j++)
					cout << "0 ";
				cout << "1 0 -1";
				for (int j = j_ + 3; j < n; j++)
					cout << " 0";
				cout << '\n';
				j_++;
			}
			for (int j = 0; j < j_; j++)
				cout << "0 ";
			cout << "1 -1 -1";
			for (int j = j_ + 3; j < n; j++)
				cout << " 0";
			cout << '\n';
			j_++;
		}
		for (int j = 0; j < n - 2; j++)
			cout << "0 ";
		cout << "1 -1\n";
		cout << "1 1";
		for (int j = 2; j < n; j++)
			cout << " 0";
		cout << '\n';
	}
	return 0;
}
