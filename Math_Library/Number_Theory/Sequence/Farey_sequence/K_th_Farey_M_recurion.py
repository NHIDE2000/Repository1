"""
分母がM以下のファレイ数列で1以下のもののうち、0/1を0番目として K番目のファレイ数列の項を p/q(p,qは互いに素)とした時、(p,q)を返します。
非再帰ver.と比べて時間計算量、空間計算量的に悪く、探索範囲も狭いです。
"""
from collections import deque
stack = deque([(0,1,1,1)])
cnt = 0
P,Q = 0,0
M,K = map(int,input().split())
while cnt <= K and stack:
    pi,qi,Pi,Qi = stack.popleft()
    if qi + Qi > M:
        P,Q = pi,qi
        cnt += 1
    else:
        stack.appendleft((pi + Pi,qi + Qi,Pi,Qi))
        stack.appendleft((pi,qi,pi + Pi,qi + Qi))
if cnt <= K:
    print(-1)
else:
    print(P,Q)