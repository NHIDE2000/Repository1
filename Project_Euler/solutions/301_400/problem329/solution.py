"""
時間計算量は MAXN = 500,CALL = 15として、O(MAXN*CALL)です。以下のPy実装でおよそ1秒未満で解答を得ることができます。
"""

MAXN = 500
CALL = 15

isprime = [True]*(MAXN + 1)
isprime[0] = isprime[1] = False
for p in range(2, MAXN + 1):
    if isprime[p] == True:
        for j in range(2*p, MAXN + 1, p):
            isprime[j] = False

num,den = 0,(6**CALL)*MAXN
S = "PPPPNNPPPNPPNPN"

dp = [[0]*(MAXN + 2) for i in range(CALL + 1)]
for i in range(1,MAXN + 1):
    dp[0][i] = 6**CALL

for i in range(CALL):
    #dp[i] -> dp[i + 1]
    if S[i] == "P":
        for j in range(1,MAXN + 1):
            if isprime[j] == True:
                #as frog said
                if 1 < j < MAXN:
                    dp[i + 1][j - 1] += dp[i][j]//3
                    dp[i + 1][j + 1] += dp[i][j]//3
                elif j == 1:
                    dp[i + 1][j + 1] += dp[i][j]*2//3
                elif j == MAXN:
                    dp[i + 1][j - 1] += dp[i][j]*2//3
            else:
                #NOT as frog said
                if 1 < j < MAXN:
                    dp[i + 1][j - 1] += dp[i][j]//6
                    dp[i + 1][j + 1] += dp[i][j]//6
                elif j == 1:
                    dp[i + 1][j + 1] += dp[i][j]//3
                elif j == MAXN:
                    dp[i + 1][j - 1] += dp[i][j]//3              

    elif S[i] == "N":
        for j in range(1,MAXN + 1):
            if isprime[j] == False:
                #as frog said
                if 1 < j < MAXN:
                    dp[i + 1][j - 1] += dp[i][j]//3
                    dp[i + 1][j + 1] += dp[i][j]//3
                elif j == 1:
                    dp[i + 1][j + 1] += (dp[i][j]*2)//3
                elif j == MAXN:
                    dp[i + 1][j - 1] += (dp[i][j]*2)//3
            else:
                #NOT as frog said
                if 1 < j < MAXN:
                    dp[i + 1][j - 1] += dp[i][j]//6
                    dp[i + 1][j + 1] += dp[i][j]//6
                elif j == 1:
                    dp[i + 1][j + 1] += dp[i][j]//3
                elif j == MAXN:
                    dp[i + 1][j - 1] += dp[i][j]//3   

num = sum(dp[CALL][i] for i in range(1,MAXN + 1))

from math import gcd
g = gcd(num,den)

print("{}/{}".format(num//g,den//g))