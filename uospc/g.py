# import sys
# s = list(input())
# ls = [[0] for _ in range(10)]

# for i, x in enumerate(s):
#     ls[int(x)].append(i+1)

# def bs(idx, n):
#     s= 0; e = len(ls[idx])-1
#     if ls[idx][-1] <= n: return -1
#     while (s<e):
#         mid = (s+e)//2
#         if ls[idx][mid] <= n: s = mid + 1
#         else: e = mid
    
#     return ls[idx][e]

# for i in range(1, 20500):
#     x = str(i)
#     sidx = 0
#     for j in range(len(x)):
#         sidx = bs(int(x[j]), sidx)
#         if sidx==-1: print(x); quit()
