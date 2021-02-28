import itertools
import math
import time

N = 16
start = time.time()
MAXN = pow(10, N)
MAX_LOOP = 55
perm = [i for i in range(1, N + 11)]
cnt = 0


def factorial_sum(LIST, power_th):
    return sum(elem*(idx**power_th) for idx, elem in enumerate(LIST))


def ordered_number(NUMBER):
    NUMBER = list(str(NUMBER))
    NUMBER.sort()
    return int("".join(NUMBER))


DATA = []
for elem in itertools.combinations(perm, 10):
    DIGIT_LIST = []
    NUM_LIST = []
    if elem[-1] != N + 10:
        continue
    for i in range(10):
        if i == 0:
            DIGIT_LIST.append(elem[0] - 1)
            NUM_LIST.append(str(i)*(elem[0] - 1))
        else:
            DIGIT_LIST.append(elem[i] - elem[i - 1] - 1)
            NUM_LIST.append((str(i))*(elem[i] - elem[i - 1] - 1))
    DATA.append((tuple(DIGIT_LIST), int("".join(NUM_LIST))))

SETS = set([])
for elem, num in DATA:
    for i in range(1, MAX_LOOP + 1):
        v = factorial_sum(elem, i)
        if v >= MAXN:
            break
        if ordered_number(v - 1) == num:
            SETS.add(v - 1)
        if ordered_number(v + 1) == num:
            SETS.add(v + 1)

ans = sum(SETS)
print(ans)
end_time = time.time() - start
print("TIME: {} (sec)".format(round(end_time, 9)))