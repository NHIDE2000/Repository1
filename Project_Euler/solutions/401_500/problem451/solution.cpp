/*

M = 2 * 1e7とします。
この解法の計算量はO(N*logN*log(M))です。空間計算量はO(M*logM)です。以下のC++実装ではおよそ3分ほどで回答を得ることができます。

*/
#include <bits/stdc++.h>
#define int long long
#define print(a) cout << (a) << endl
using namespace std;
template <class T>bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
template <class T>bool chmin(T &a, T b){if (a > b){a = b;return true;}return false;}
template <class T = int>T gcd(T a, T b){return (b == 0) ? a : gcd(b, a % b);}
template <class T = int>T extgcd(T a,T b,T &x,T &y){T g = a;x = 1;y = 0;if (b != 0) {g = extgcd(b, a % b, y, x), y -= (a / b) * x;}return g;}
template<class T = int> T invMod(T a,T m){T x,y;if (extgcd(a, m, x, y) == 1) {return (x + m) % m;}else{return -1;}}


int crt(int modp, int p, int modq, int q,int M){
    int g = gcd(p,q);
    if ((modq - modp) % g != 0){return -1;}
        int K = (modq - modp) / g;
        int y1 = p/g,y2 = q/g;
        int t = (-K * invMod(y2, y1))%y1;
        int m = (modq + (t%y1) * g * y2) % (g*y1*y2);
        while (m + g*y1*y2 < M - 1){m += g*y1*y2;}
        return m;
}
const int MAXN = 20000000;
vector<vector<int>> DIVISORS(MAXN + 1,vector<int>{});

void DIVISORS_SETUP(){
    for (int d = 1; d<= MAXN;d++){
        for (int n = d; n <= MAXN; n += d){
            DIVISORS[n].push_back(d);
        }
    }
    return;
}

int f(int N){
    int tmp = 0;
    int ans = 1;
    for (auto d: DIVISORS[N]){
        tmp = crt(-1,d,1,N/d,N);
        if (tmp < N - 1){chmax(ans,tmp);}
    }
    return ans;
}
signed main(){
    DIVISORS_SETUP();

    int ans = 0;
    for (int n = 3; n <= MAXN;n ++){
        ans += f(n);
    }
    print(ans);
}