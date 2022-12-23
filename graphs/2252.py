from collections import deque

N,M = map(int, input().split())

A = {}
for i in range(M):
  a,b = map(int, input().split())
  a -= 1
  b -= 1

  if a in A.keys():
    A[a].append(b)
  else:
    A[a] = [ b ]

def BFS(A):
  res = []
  visited = [0] * N
  deg = [0] * N
  for sup in A.keys():
    for sub in A[sup]:
      deg[sub] += 1

  queue = deque([])
  for i in range(N):
    if deg[i] == 0:
      queue.append(i)

  while queue:
    v = queue.popleft()
    visited[v] = 1
    res.append(v)

    if v not in A.keys():
      continue
    for w in A[v]:
      if visited[w] == 0:
        deg[w] -= 1
        if deg[w] == 0:
          queue.append(w)

  return res

result = BFS(A)
for v in result:
  print(v+1, end=' ')