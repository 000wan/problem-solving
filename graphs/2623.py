from collections import deque
from collections import defaultdict

A = defaultdict(list)
N,M = list(map(int, input().split()))
for i in range(M):
    a = list(map(int, input().split()))
    for j in range(1, len(a)-1):
        A[a[j]].append(a[j+1]);

def BFS():
  deg = [0] * (N+1)
  for sup in A.keys():
    for sub in A[sup]:
      deg[sub] += 1
    
  res = []
  queue = deque([])
  for i in range(1, N+1):
    if deg[i] == 0:
      queue.append(i)

  while queue:
    v = queue.popleft()
    res.append(v)
    for w in A[v]:
      deg[w] -= 1
      if deg[w] == 0:
        queue.append(w)

  if (len(res) == N):
      for item in res:
          print(item)
  else:
      print(0)

BFS()

