#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define print(a) cout << (a) << endl
#define len(X) ((int)(X).size())
using namespace std;

template <class T = int>T gcd(T a, T b){return (b == 0) ? a : gcd(b, a % b);}
template <class T = int>T extgcd(T a,T b,T &x,T &y){T g = a;x = 1;y = 0;if (b != 0) {g = extgcd(b, a % b, y, x), y -= (a / b) * x;}return g;}
template<class T = int> T invMod(T a,T m){T x,y;if (extgcd(a, m, x, y) == 1) {return (x + m) % m;}else{return -1;}}

int crt(int modp, int p, int modq, int q){
    int g = gcd(p,q);
    if ((modq - modp) % g != 0){return -1;}
        int K = (modq - modp) / g;
        int y1 = p/g,y2 = q/g;
        int t = (-K * invMod(y2, y1))%y1;
        int m = (modq + (t%y1) * g * y2) % (g*y1*y2);
        while (m < 0){m += g*y1*y2;}
        return m;
}

struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> min_factor;

    Eratos(int MAX) : primes(),
                      isprime(MAX+1, true),
                      min_factor(MAX+1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            min_factor[i] = i;
            for (int j = i*2; j <= MAX; j += i) {
                isprime[j] = false;
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    vector<pair<int,int>> prime_factorize(int n) {
        vector<pair<int,int> > res;
        while (n != 1) {
            int prime = min_factor[n];
            int exp = 0;
            while (min_factor[n] == prime) {
                ++exp;
                n /= prime;
            }
            res.push_back(make_pair(prime, exp));
        }
        return res;
    }
};

const int MAXN = 1e6;
Eratos PRIMES(MAXN + 10000);
vector<int> PrimeV= PRIMES.primes;

int NUM_LENGTH(int M){
    int res = 1;
    while (M){res *= 10;M/=10;}
    return res;
}

signed main(){
    int ans = 0;
    rep(i,len(PrimeV) - 1){
        int p1 = PrimeV[i],p2 = PrimeV[i + 1];
        if (p1 > MAXN || p1 <= 3){continue;}    
        int res =  crt(p1,NUM_LENGTH(p1),0,p2);
        ans += res;
    }
    print(ans);
    return 0;
}