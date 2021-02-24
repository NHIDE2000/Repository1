#include <bits/stdc++.h>
#define int long long
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define print(a) cout << (a) << endl
using namespace std;
const int MAXN = 50000000;

vector<int> COUNT(MAXN + 1,0);
signed main(){
    rep1(z,MAXN){
        for (int d = z/3;d <= MAXN; d++){
            int n = (d + z)*(3*d - z);
            if (n > MAXN){break;}
            if (n >= 0){COUNT[n]++;}
        }
    }
    int ans = 0;
    rep1(i,MAXN){if (COUNT[i] == 1){ans++;}}
    print(ans);
    return 0;
}