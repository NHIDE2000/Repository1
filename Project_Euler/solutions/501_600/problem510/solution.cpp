#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define print(a) cout << (a) << endl
using namespace std;
template <class T = int>T gcd(T a, T b){return (b == 0) ? a : gcd(b, a % b);}
const int MAXN = 1e9;

signed main(){
    int ans = 0;
    int sqrtMAXN = 1;
    while (sqrtMAXN*sqrtMAXN <= MAXN){sqrtMAXN++;}
    rep1(sqa,sqrtMAXN)rep1(sqb,sqrtMAXN){
        int a = sqa*sqa,b = sqb*sqb;
        if ((a*b) % (a + b + 2*sqa*sqb) == 0){
            int c = (a*b) / (a + b + 2*sqa*sqb);
            int G = gcd(gcd(a,b),c);
            if (1 <= a && a <= b && b <= MAXN && G == 1){
                int L = MAXN/b;
                ans += L*(L + 1)/2*(a + b + c);
            }
        }
    }
    print(ans);
    return 0;
}