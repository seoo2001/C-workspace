import sys
rl = sys.stdin.readline
dp = [[[-10**9 for _ in range(512)] for _ in range(501)] for _ in range(501)]

n = int(rl())
ns = [0] + list(map(int, rl().split()))

for i in range(1, n+1): dp[i][i][ns[i]] = 1

for j in range(1, n):
    for i in range(1, n+1-j):
        for k in range(0, 512):
            dp[i][i+j][k] = max(dp[i][i+j-1][k], dp[i+1][i+j][k], dp[i+1][i+j][k^ns[i]] + 1, dp[i][i+j-1][k^ns[i+j]] + 1)

m = int(rl())
for _ in range(m):
    l, r = map(int, rl().split())
    ans = 0
    for i in range(512):
        ans = max(ans, dp[l][r][i]+i)
    print(ans)