/*

時間計算量は　N = 64000000 として O(NlogN)です。以下のC++実装ではおよそ50秒ほどで解答を得ることができます。

*/

#include <bits/stdc++.h>
#define int long long
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define print(a) cout << (a) << endl
using namespace std;



const int MAXN = 64000000;
vector<int> a(MAXN + 1,0);

bool is_square(int M){
    int l = 0,r = 1e9;
    while (r - l > 1){
        int med = (r + l)/2;
        if (med * med >= M){r = med;}
        else{l = med;}
    }
    return r * r == M;
}

signed main(){
    rep1(i,MAXN){
        for (int j = i; j <= MAXN; j += i){a[j] += i * i;}
    }
    int ans = 0;
    rep1(i,MAXN - 1){
        if (is_square(a[i]) == true){ans += i;}
    }
    print(ans);
    return 0;
}