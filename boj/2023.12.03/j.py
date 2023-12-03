import sys
rl = sys.stdin.readline

n = int(rl())

g = [list(rl().split()) for _ in range(n)]

for i in range(n):
    if (g[i][0].find('x')!=-1):
        idx = g[i][0].find('x')
        print(g[i][1][idx].upper(), end='')
    else:
        idx = g[i][0].find('X')
        print(g[i][1][idx].upper(), end='')