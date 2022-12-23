N,M = map(int, input().split())
A = []
for i in range(N):
  A.append([])
  inp = input()
  for s in inp:
    A[i].append(int(s == 'B')) # B 1 W 0

row = []
row.append([ i%2 for i in range(M) ])
row.append([ (i+1)%2 for i in range(M) ])
WBoard = [row[i%2] for i in range(N)]
# BBoard = [row[(i+1)%2] for i in range(N)]

D = []
for i in range(N):
  D.append([])  
  for j in range(M):
    D[i].append(int(not A[i][j] == WBoard[i][j]))

def msum(a,b,l,arr):
  res = 0
  for i in range(a, a+l):
    for j in range(b, b+l):
      res += arr[i][j]
  return res

rmax = 0
rmin = 64
for i in range(N-7):
  for j in range(M-7):
    res = msum(i,j,8,D)
    rmax = max(rmax, res)
    rmin = min(rmin, res)
result = min(rmin, 64-rmax)

print(result)