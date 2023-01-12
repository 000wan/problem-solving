N = int(input())
dp = [[0, 1] for i in range(10)]

for i in range(2, N+1):
  dp[0].append(dp[1][i-1])
  dp[9].append(dp[8][i-1])
  for d in range(1, 9):
    dp[d].append(dp[d-1][i-1] + dp[d+1][i-1])

res = 0
for d in range(1, 10):
  res += dp[d][N]
  res %= 1000000000

print(res)