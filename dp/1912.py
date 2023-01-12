# Sol1. DP
N = int(input())
n = list(map(int, input().split()))
dp = [-1] * N
dp[0] = n[0]

M = dp[0]
for i in range(1,N):
  dp[i] = max(dp[i-1], 0) + n[i]
  M = max(M, dp[i])

print(M)

# Sol2. O(N)
N = int(input())
n = list(map(int, input().split()))

M = -1001
res = 0
for i in range(N):
  res += n[i]

  M = max(M, res)
  if res <= 0:
    res = 0

print(M)