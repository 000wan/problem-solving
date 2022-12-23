# BFS based topological sort
'''
from collections import deque
def BFS(A, D, N, W, memo):
  deg = [0] * N
  for sup in A.keys():
    for sub in A[sup]:
      deg[sub] += 1

  queue = deque([])
  for i in range(N):
    if deg[i] == 0:
      queue.append(i)
      memo[i] = D[i]

  while queue:
    v = queue.popleft()

    if v in A.keys():
      for w in A[v]:
        deg[w] -= 1
        memo[w] = max(memo[w], memo[v]+D[w])

        if deg[w] == 0:
          queue.append(w)
          if w == W:
            break

  return memo[W]
  '''

# DFS based topological sort
from collections import defaultdict

def DFS(v, A, D, memo):
  if not memo[v] == -1:
    return memo[v]
  
  res = D[v]
  if v in A.keys():
    for w in A[v]:
      res = max(res, DFS(w, A, D, memo) + D[v])
  
  memo[v] = res
  return memo[v]

T = int(input())
result = []
for epoch in range(T):
  N,K = map(int, input().split())
  D = list(map(int, input().split()))
  
  A_inv = defaultdict(list)
  for i in range(K):
    v0,v1 = map(lambda x: int(x)-1, input().split())
    A_inv[v1].append(v0)

  W = int(input()) - 1

  memo = [-1] * N
  result.append(DFS(W, A_inv, D, memo))

for res in result:
  print(res)
