M = int(input())
N = int(input())

P = [True] * (N+1)
P[0] = P[1] = False
for i in range(2, int(N**0.5)+1):
    j = 2
    while i*j <= N:
        P[i*j] = False
        j += 1

for a in range(M, N+1):
    if not P[a]:
        continue
    print(a)