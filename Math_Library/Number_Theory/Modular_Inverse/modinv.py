"""
整数a,mに対して ax = 1(modulo m)なる最小の自然数xを返します。存在しない場合はFalseを返します。
時間計算量は対数時間です。
"""

def xgcd(a, b):
    x0, y0, x1, y1 = 1, 0, 0, 1
    while b:
        q, a, b = a // b, b, a % b
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return a, x0, y0
 
 
def modinv(a, m):
    g, x, y = xgcd(a, m)
    if g != 1:
        return False
    else:
        return x % m