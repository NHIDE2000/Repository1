/*
1000以上5000以下の素数の個数をNとします。時間計算量は O(N**3 * log) ほどです。以下のC++実装ではおよそ30秒ほどで解答を得ることができます。
*/

#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define print(a) cout << (a) << endl
#define len(X) ((int)(X).size())
using namespace std;

template <class T = int>T gcd(T a, T b){return (b == 0) ? a : gcd(b, a % b);}
template<class T = int>T powMod(T x, T k, T m) {if (k == 0){return (T)1;}if (k % 2 == 0) {return powMod(x*x % m, k/2, m);}else{return x*powMod(x, k-1, m) % m;}}
template <class T = int>T extgcd(T a,T b,T &x,T &y){T g = a;x = 1;y = 0;if (b != 0) {g = extgcd(b, a % b, y, x), y -= (a / b) * x;}return g;}
template<class T = int> T invMod(T a,T m){T x,y;if (extgcd(a, m, x, y) == 1) {return (x + m) % m;}else{return -1;}}


const int MAXSIZE = 1e4;

vector<int> fact(MAXSIZE + 1,1);
vector<int> invfact(MAXSIZE + 1,1);


void setup_combination(int MOD){
    rep1(i,MOD - 1){
        fact[i] = fact[i - 1]*i%MOD;
    }
    invfact[MOD - 1] = powMod(fact[MOD - 1],MOD - 2,MOD);
    rrep1(i,MOD - 1){
        invfact[i - 1] = invfact[i]*i%MOD;
    }
    return;
}

int Com(int N, int R,int MOD){
    if (!(N >= R && R >= 0)) { return 0;}
    int res = fact[N];
    res *= invfact[R];res %= MOD;
    res *= invfact[N - R]; res %= MOD;
    while (res < 0){res += MOD;}
    return res;
}



int NCR(int X,int Y,int p){
    //Lucas theorem
    setup_combination(p);
    int N = X,R = Y;
    int res = 1;
    while (N > 0){
        int n = N/p;int modn = N%p;while (modn < 0){modn += p;}
        int r = R/p;int modr = R%p;while (modr < 0){modr += p;}
        res *= Com(modn,modr,p);res %= p;
        N = n;R = r;
    }
    while (res < 0){res += p;}
    return res;
}

int crt(int modp, int p, int modq, int q){
    int g = gcd(p,q);
    if ((modq - modp) % g != 0){return -1;}
        int K = (modq - modp) / g;
        int y1 = p/g,y2 = q/g;
        int t = (-K * invMod(y2, y1))%y1;
        int m = (modq + t * g * y2) % (g*y1*y2);
        while (m < 0){m += g*y1*y2;}
        return m;
}

const int SIZE = 5000;
vector<bool> ISPRIME(SIZE + 1,true);

void PRIME_SEIVE(vector<bool> & vec){
    int L = len(vec) - 1;
    vec[0] = vec[1] = false;
    for (int p = 2; p <= L; p++){
        if (vec[p] == true){for(int j = 2*p;j <= L; j+= p){vec[j] = false;}}
    }
    return;
}

signed main(){
    int X = 1e18;
    int Y = 1e9;
    PRIME_SEIVE(ISPRIME);
    vector<int> PRIMES{};
    for (int i = 1000;i < 5000;i++){if(ISPRIME[i] == true){PRIMES.push_back(i);}}
    map<int,int> D;
    for (int p : PRIMES){D[p] = NCR(X,Y,p);}
    int ans = 0; 
    for(int p : PRIMES)for (int q:PRIMES)for(int r:PRIMES){
        if (p >= q || q >= r){continue;}
        //p < q < r
        int modpq = crt(D[p],p,D[q],q);
        int res = crt(modpq,p*q,D[r],r);
        ans += res;
    }
    print(ans);
    return 0;
}