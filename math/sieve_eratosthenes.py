def sieve(N):
    P = [i for i in range(N+1)]
    P[0] = P[1] = -1

    for i in range(2, int(N**0.5)+1):
        if P[i] != i: # not a prime
            continue

        j = 2
        while i*j <= N:
            if P[i*j] == i*j: # not checked yet
                P[i*j] = i
            j += 1
    return P

# Find prime numbers
M = int(input())
N = int(input())

P = sieve(N)
for a in range(M, N+1):
    if not P[a] == a:
        continue
    print(a)

# BOJ 16563 Prime Factorization
N = int(input())
SUP = 5000000

P = sieve(SUP)

ki = list(map(int, input().split()))
for i in range(N):
    k = ki[i]
    while P[k] != k:
        print(P[k], end=' ')
        k //= P[k]
    print(k)