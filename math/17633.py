import sys
input = sys.stdin.readline

def gcd(m, n):
  while n != 0:
    t = m%n
    m,n = n,t
  return m

def fast_power(a, b, m): # a^b % m
    a %= m
    res = 1
    while b > 0:
        if b % 2:
            res = (res * a) % m
        a = (a * a) % m
        b //= 2
    return res

import random
# Pollard's rho algorithm: Find prime factor, random, O(n^1/4)
def pollard_rho(n):
    if (n == 1):
        return 1
    if (n%2 == 0):
        return 2
    if is_prime(n):
        return n

    x = random.randint(2, n-1)
    y = x
    c = random.randint(1, n-1) # random constant
    
    d = 1 # gcd
    while (d == 1):
        # x->f(x)
        x = (fast_power(x, 2, n) + c) % n
        # y->f(f(y))
        y = (fast_power(y, 2, n) + c) % n
        y = (fast_power(y, 2, n) + c) % n
        d = gcd(abs(x-y), n)
        
    if (d == n): return pollard_rho(n) # retry
    elif (not is_prime(d)): return pollard_rho(d) # factor d
    else: return d

def prime_factor(n):
    factor = []
    while (n > 1):
        p = pollard_rho(n)
        factor.append(p)
        n //= p
    factor.sort()
    return factor

# Miller-Rabin test: Check is prime in O(klog^3n)
def miller_rabin(n, a): # true: probable prime, false: composite 
    d = n-1
    while d%2 == 0:
        if fast_power(a, d, n) == n-1:
            return True
        d //= 2
    ad = fast_power(a, d, n) 
    return (ad == n-1 or ad == 1)

def is_prime(n):
    alist = [2,7,61] # for n < 2^32
    alist = [2,3,5,7,11,13,17,19,23,29,31,37] # for n < 2^64
    if n <= 1:
        return False
    if n in alist:
        return True
    for a in alist:
        if not miller_rabin(n, a):
            return False
    return True

def main():
    N = int(input())
    factor = prime_factor(N)
    e = {}
    for p in factor:
        if (p in e.keys()):
            e[p] += 1
        else:
            e[p] = 1
    
    one = True
    two = True
    for p in e:
        if (e[p]%2 == 1):
            one = False
            two &= (p%4 != 3)
    if (one):
        print(1)
        return
    elif (two):
        print(2)
        return
    
    n = N
    while (n%4 == 0):
        n //= 4
    if (n%8 != 7):
        print(3)
        return
    else:
        print(4)
        return
        
main()
