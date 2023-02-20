def power(a, b, c):
    a = a%c
    res = 1
    while (b > 0):
        if (b % 2 == 1):
            res = (res * a) % c
        a = (a*a)%c
        b //= 2
    return res
def gcd(m,n):
    while (n > 0):
        t = m%n
        m = n
        n = t
    return m

N = int(input())
a = []
for i in range(N):
    a.append(input())
K = int(input())

lens = [-1 for i in range(2**N)]
def init(visited):
    if (visited == 0):
        return 0
    if (lens[visited] != -1):
        return lens[visited]

    i = 1
    for t in range(N):
        if (visited & i):
            lens[visited] = len(str(a[t])) + init(visited ^ i)
            break
        i *= 2
    return lens[visited]

memo = [[-1 for i in range(K)] for j in range(2**N)]
def dp(visited, k):
    if (visited == 0):
        return int(k == 0)
    if (memo[visited][k] != -1):
        return memo[visited][k]

    res = 0
    i = 1
    for t in range(N):
        if (visited & i):
            #k = a*(10**l)%K + k2
            k2 = (k - (a[t]*power(10, init(visited ^ i), K))%K)%K
            res += dp(visited^i, k2)
        i *= 2
    memo[visited][k] = res
    return res

p = dp(2**N-1, 0)
q = 1
for i in range(1, N+1):
    q *= i
g = gcd(p, q)
print(f'{p//g}/{q//g}')

