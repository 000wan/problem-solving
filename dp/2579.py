N = int(input())
S = [0]
for i in range(N):
  S.append(int(input()))

memo = [[-1,-1] for i in range(N+1)]
def search(v, flag):
  if v == N:
    return 0
  if flag != -1:
    if memo[v][flag] != -1:
      return memo[v][flag]
  
  res = -3000001
  if v+1 <= N:
    if flag < 1:
      res = max(res, S[v+1] + search(v+1, flag+1))
  if v+2 <= N:
    res = max(res, S[v+2] + search(v+2, 0))
  
  memo[v][flag] = res
  return memo[v][flag]

print(search(0, -1))