from collections import defaultdict

def DFS(v, A, visited):
  visited.append(v)

  for w in A[v]:
    if w not in visited:
      DFS(w, A, visited)
  
  return

N,M = map(int, input().split())
starts = list(map(int, input().split()))
if len(starts) <= 1:
  starts = []
else:
  starts = starts[1:]

P = []
Adj = defaultdict(list)
for i in range(M):
  inp = list(map(int, input().split()))
  P.append(inp[1:])
  
  l = inp[0]
  for p1 in range(l):
    for p2 in range(p1 + 1, l):
      Adj[P[i][p1]].append(P[i][p2])
      Adj[P[i][p2]].append(P[i][p1])

blocklist = set()
for s in starts:
  res = []
  DFS(s, Adj, res)
  blocklist.update(res)

cnt = M
for i in range(M):
  for p in P[i]:
    if p in blocklist:
      cnt -= 1
      break

print(cnt)