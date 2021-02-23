/*

この解法はO(NlogN)です。なお、空間計算量はO(N)です。以下のC++実装ではおよそ30秒ほどで回答を得ることができます。

*/

#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define print(a) cout << (a) << endl
#define len(X) ((int)(X).size())
using namespace std;
const int MAXN = 1e8;

vector<bool> isprime(MAXN + 1,true);
vector<int> phi(MAXN + 1);

void setup(){
    isprime[0] = isprime[1] = false;
    rep(i,MAXN + 1){phi[i] = i;}
    for (int p = 2; p <= MAXN; p++){
        if (isprime[p] == true){
            phi[p] = p - 1;
            for (int j = 2*p;j <= MAXN;j+=p){isprime[j] = false;phi[j]/=p;phi[j]*=(p - 1);}
        }
    }
    return;
}

signed main(){
    int M = 1e8;
    setup();
    int ans = M*M;
    for (int j = 2; j <= M;j++){ans -= 2*phi[j];}
    ans--;
    ans += (M - 1);
    ans *= 3;
    print(ans);
    return 0;
}