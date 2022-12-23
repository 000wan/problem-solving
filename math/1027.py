N = int(input())
y = list(map(int, input().split()))

W = [[0 for i in range(N)] for j in range(N)]

for i in range(N):
  for j in range(i+1, N):
    W[i][j] = (y[j]-y[i])
    W[j][i] = W[i][j]

res = []
for i in range(N):
  cnt = 0

  prevY = 0
  prevX = 0
  for j in range(i-1, -1, -1):
    if j == i-1 or W[i][j] * prevX < prevY * (i-j):
      prevY = W[i][j]
      prevX = i-j
      cnt += 1
  prevY = 0
  prevX = 0
  for j in range(i+1, N):
    if j == i+1 or W[i][j] * prevX > prevY * (j-i):
      prevY = W[i][j]
      prevX = j-i
      cnt += 1
  
  res.append(cnt)
print(max(res))