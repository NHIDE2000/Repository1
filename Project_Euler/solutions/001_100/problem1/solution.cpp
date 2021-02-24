#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define print(a) cout << (a) << endl
using namespace std;

const int MAXN = 1000;

signed main(){
    int ans = 0;
    rep(i,MAXN){
        if (i % 3 == 0|| i %5 == 0){ans+=i;}
    }
    print(ans);
    return 0;
}