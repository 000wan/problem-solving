import heapq

N,K = map(int, input().split())
S = []
adj = []
D = []
pq = []
for i in range(N):
  S.append(int(input()))
  adj.append([i-1, i+1])
  if i > 0:
    D.append(S[i]-S[i-1])
    heapq.heappush(pq, ( D[i-1], (i-1, i) )) # first for sort, second for save
D.append(0)

cnt = 0
res = 0

while cnt < K:
  e = heapq.heappop(pq)
  d = e[0]
  ran = e[1]
  left = adj[ran[0]]
  right = adj[ran[1]]
  if ran[0] < 0 or ran[1] > N-1:
    continue
  if ran[0] != right[0] or ran[1] != left[1]: # must be adjacent
    continue
  
  res += d
  cnt += 1
  nleft = left[0]
  nright = right[1]
  if nleft >= 0:
    adj[nleft][1] = nright
  if nright <= N-1:
    adj[nright][0] = nleft
  
  if 0 <= nleft and nright <= N-1:
    D[nleft] = D[nleft] - d + D[ran[1]]
    heapq.heappush(pq, ( D[nleft], (nleft, nright) ))

print(res)