"""
分母がM以下のファレイ数列のうち、0/1を0番目として K番目のファレイ数列の項を p/q(p,qは互いに素)とした時、(p,q)を返します。
時間計算量はlog(M)*Kです。
"""
def f(h, k, N):
    x = pow(k, -1, h)
    y = (k * x - 1)// h
    p = (N - y)// k
    return x + p*h, y + p*k
M, K = map(int, input().split())
p, q = 1, M
for i in range(K - 1):
    p, q = f(p, q, M)
print(p,q)