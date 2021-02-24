#include <bits/stdc++.h>
#define int long long
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define print(a) cout << (a) << endl
using namespace std;
const int MAXN = 1000000;

vector<vector<int>> DIVISORS(MAXN + 1,vector<int>{});

void DIVISORS_SETUP(){
    rep1(i,MAXN){
        for (int j = i; j <= MAXN;j+=i){DIVISORS[j].push_back(i);}
    }
    return;
}

int ANS_COUNT(int M){
    int res = 0;
    for (auto d:DIVISORS[M]){
        int u = d,v = M/d;
        if ((u + v) % 4 == 0 && (3*u - v) % 4 == 0 and 3*u > v){
            res++;
        }
    }
    return res;
}

signed main(){
    DIVISORS_SETUP();
    int ans = 0;
    rep1(i,MAXN){ if (ANS_COUNT(i) == 10){ans++;}}
    print(ans);
    return 0;
}