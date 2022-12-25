N,L = map(int, input().split())
M = 2*N
d = set()
for i in range(1, int(M**0.5)+1):
  if M % i == 0:
    d.add(i)
    d.add(M//i)

a = -1
n = -1
for div in d:
  if div >= L:
    q = M//div
    if (q-div+1)%2 == 1 or (q-div+1) < 0:
      continue
    n = div
    a = (q-div+1)//2
    break

if n == -1 or n > 100:
  print(-1)
else:
  res = list(range(a, a+n))
  print(*res)