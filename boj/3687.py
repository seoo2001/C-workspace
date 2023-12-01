import sys
rl = sys.stdin.readline

n = int(rl())

ml = [10**20 for _ in range(101)]
ml[2] = 1
ml[3] = 7
ml[4] = 4
ml[5] = 2
ml[6] = 6
ml[7] = 8

def f(x, y):
    if x==0 and y==0: return 10**20
    if y==0: return x*10
    if x==0: return y*10
    return min(int(str(x)+str(y)), int(str(y)+str(x))) 
for i in range(8, 101):
    for j in range(2, i-1):
        if j==6: ml[i] = min(ml[i], f(0, ml[i-j]))
        ml[i] = min(ml[i], f(ml[j], ml[i-j]))

for i in range(n):
    x = int(rl())
    print(ml[x], end= ' ')
    if x%2==1:
        print(7, end='')
        print(''.join(['1' for _ in range((x-3)//2)]))
    else: print(''.join(['1' for _ in range(x//2)]))
