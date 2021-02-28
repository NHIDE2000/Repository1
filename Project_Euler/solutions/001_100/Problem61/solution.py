from itertools import permutations
MAXN = 10000
LOW_BOUND = int(1e3)
BOUND = int(1e4)

Triangle = []
for i in range(1, MAXN):
    d = i*(i + 1)//2
    if d < LOW_BOUND:
        continue
    if d > BOUND:
        break
    Triangle.append(d)


Square = []
for i in range(1, MAXN):
    d = i*i
    if d < LOW_BOUND:
        continue
    if d > BOUND:
        break
    Square.append(d)


Pentagonal = []
for i in range(1, MAXN):
    d = i*(3*i - 1)//2
    if d < LOW_BOUND:
        continue
    if d > BOUND:
        break
    Pentagonal.append(d)


Hexagonal = []
for i in range(1, MAXN):
    d = i*(2*i - 1)
    if d < LOW_BOUND:
        continue
    if d > BOUND:
        break
    Hexagonal.append(d)


Heptagonal = []
for i in range(1, MAXN):
    d = i*(5*i - 3)//2
    if d < LOW_BOUND:
        continue
    if d < LOW_BOUND:
        continue
    if d > BOUND:
        break
    Heptagonal.append(d)


Octagonal = []
for i in range(1, MAXN):
    d = i*(3*i - 2)
    if d < LOW_BOUND:
        continue
    if d > BOUND:
        break
    Octagonal.append(d)


GROUPS = ["Triangle", "Square", "Pentagonal",
          "Hexagonal", "Heptagonal", "Octagonal"]


exec_template = """
for elema in {group1}:
    for elemb in {group2}:
        if elema % 100 != elemb//100:
            continue
        for elemc in {group3}:
            if elemb % 100 != elemc // 100:
                continue
            for elemd in {group4}:
                if elemc % 100 != elemd//100:
                    continue
                for eleme in {group5}:
                    if elemd % 100 != eleme // 100:
                        continue
                    for elemf in {group6}:
                        if eleme % 100 == elemf // 100 and elemf % 100 == elema // 100:
                            print(elema + elemb + elemc +
                                  elemd + eleme + elemf)
                            break
"""


"ループの開始地点で6通り考えられるため、答えは6回出力されます。"
for (g1, g2, g3, g4, g5, g6) in permutations(GROUPS):
    exe = exec_template.format(group1=g1, group2=g2, group3=g3, group4=g4, group5=g5, group6=g6)
    exec(exe)
