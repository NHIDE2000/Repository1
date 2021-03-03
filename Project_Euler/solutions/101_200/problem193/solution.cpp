/*
N = 2^25とします。時間計算量は O(NlogN)です。以下のC++実装ではおよそ10秒ほどで解答を得ることができます。
*/

#include <bits/stdc++.h>
#define int long long
#define print(a) cout << (a) << endl
using namespace std;


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

    // prime factorization
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

const int MAXN = pow(2,25);
Eratos PRIMES(MAXN);
signed main(){
    int M = pow(2,50);
    int sqrt = 1;while ( (sqrt + 1)*(sqrt + 1) <= M){sqrt++;}
    int nsqf = 0;
    for (int i = 2; i<= sqrt;i++){
        auto vec = PRIMES.prime_factorize(i);
        int difp = 0;
        bool flag = true;
        for (auto [p,ord]:vec){if (ord != 1){flag = false;} else{difp++;}}
        if (flag == false){continue;}
        if (difp % 2 != 0){nsqf += M/(i*i);}
        else{nsqf -= M/(i*i);}
    }
    int ans = M - nsqf;
    print(ans);
    return 0;
}