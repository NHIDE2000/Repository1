/*
時間計算量はO(K)です。　以下のC++実装ではおよそ1分ほどで解答得ることができます。
*/

#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define print(a) cout << (a) << endl
using namespace std;


const int MAXN = 1e8;
const int MOD = 1e9 + 7;

vector<int> fact(MAXN + 1,1);
vector<int> invfact(MAXN + 1,1);

int powMod(int x, int k, int m) {
  if (k == 0)     return 1;
  if (k % 2 == 0) return powMod(x*x % m, k/2, m);
  else            return x*powMod(x, k-1, m) % m;
}

void setup(){
    rep1(i,MAXN){
        fact[i] = fact[i - 1]*i%MOD;
    }
    invfact[MAXN] = powMod(fact[MAXN],MOD - 2,MOD);
    rrep1(i,MAXN){
        invfact[i - 1] = invfact[i]*i%MOD;
    }
    return;
}

int f(int k,int a){
    int res = fact[k];
    res *= invfact[a];res %= MOD;
    res *= invfact[a];res %= MOD;
    res *= invfact[k - 2*a];res %= MOD;
    return res;
}

signed main(){
    int k, n;k = 1e8; n = 1e16;
    int res = 0;
    setup();
    rep(i,k/2 + 1){
        res += f(k,i) * powMod(2,(k - 2*i)*(n/k),MOD);
        res %= MOD;
    }
    while (res < 0){res += MOD;}
    print(res);
    return 0;
}