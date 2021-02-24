MOD = (int)(1e10)
print(sum(pow(i,i,MOD) for i in range(1,1001)) % MOD)