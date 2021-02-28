def P(M):
    num,den = 0,0
    for i in range(1<<M):
        red,blue,p= 0,0,1
        for bit in range(M):
            if (i >> bit) & 1:
                red += 1
                p *= (bit + 1)
            else:
                blue += 1
        den += p 
        if red < blue:
            num += p 
    return num,den

REPEAT = 15
num, den = P(REPEAT)
print(den//num)