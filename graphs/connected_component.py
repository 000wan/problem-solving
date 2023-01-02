def DFS(v, A, visited):
  visited[v] = True
  
  for w in A[v]:
    if not visited[w]:
      DFS(w, A, visited)

def connected(N, A):
  visited = [False] * (N+1)

  cnt = 0
  for v in range(1, N+1):
    if not visited[v]:
      DFS(v, A, visited)
      cnt += 1
  
  return cnt

from collections import defaultdict
N,M = map(int, input().split())

Adj = defaultdict(list)
for i in range(M):
  u,v = map(int, input().split())
  Adj[u].append(v)
  Adj[v].append(u)

print(connected(N, Adj))