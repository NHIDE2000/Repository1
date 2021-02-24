#include <bits/stdc++.h>
#define int long long
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define print(a) cout << (a) << endl
#define elif else if

using namespace std;

template<class T = int>T powMod(T x, T k, T m) {if (k == 0){return (T)1;}if (k % 2 == 0) {return powMod(x*x % m, k/2, m);}else{return x * powMod(x, k-1, m) % m;}}
const int MOD1 = pow(5,10);
const int MOD2 = pow(2,10);
const int MAXN = 1000;
signed main(){
    int ans1 = 0,ans2 = 0;
    //ans1 = ANS % MOD1
    //ans2 = ANS % MOD2
    // gcd(MOD1,MOD2) = 1 and MOD1*MOD2 == 1e10;
    rep1(i,MAXN){ans1 += powMod(i,i,MOD1); ans1 %= MOD1;}
    rep1(i,MAXN){ans2 += powMod(i,i,MOD2); ans2 %= MOD2;}
    while (ans1 < 0){ans1 += MOD1;}
    while (ans2 < 0){ans2 += MOD2;}
    for (int ans = ans1;ans < (int)(1e10); ans += MOD1){
        if ((ans - ans2) % MOD2 == 0)
        {print(ans);return 0;}
    }
    return 0;
}