"""

この解法はO(NlogN)であるため、実行速度の観点から以下のPyの実装ではH(1e6)を求めるにとどまっています。
MAXN = 1e8とすることで所望の回答を得ることができますが、Pythonでは1分以上時間がかかることが予想されます。

"""
MAXN = int(1e6)
ISPRIME = [True]*(MAXN + 1)
PHI = [i for i in range(MAXN + 1)]


ISPRIME[0] = ISPRIME[1] = False

for p in range(2, MAXN + 1):
    if ISPRIME[p] == True:
        PHI[p] = p - 1
        for j in range(2*p, MAXN + 1, p):
            ISPRIME[j] = False
            PHI[j] //= p
            PHI[j] *= (p - 1)


M = MAXN
ans = M*M
for i in range(2, M + 1):
    ans -= 2*PHI[i]
ans -= 1
ans += M - 1
ans *= 3
print(ans)
