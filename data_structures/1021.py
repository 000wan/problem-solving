N,M = map(int, input().split())
A = list(map(int, input().split()))

def dist(i, j, length, visited):
  inside = 0
  outside = 0
  for v in visited:
    if i<=v<=j or (j<=i<=v or v<=j<=i):
      inside += 1
    else:
      outside += 1

  Din = (j - i)%length - inside
  Dout = (length - j + i)%length - outside 
  return min(Din, Dout)

res = 0
head = 1
for i in range(M):
  res += dist(head, A[i], N, A[:i])
  head = A[i]

print(res)