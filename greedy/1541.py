A = input().split('-')
res = sum(map(int, A[0].split('+')))
for i in range(1, len(A)):
  res -= sum(map(int, A[i].split('+')))
print(res)