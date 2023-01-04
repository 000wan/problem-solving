def euclidean(m, n):
  while n != 0:
    t = m%n
    m,n = n,t
  return m

def extended_euclidean(a, b):
  #
  #  /** Bezout Coefficients **/
  #
  #  Note that for k s.t. r(k)=0 :
  #  a*s(k-1) + b*t(k-1) = r(k-1) = gcd(a,b)
  #  a*s(k) + b*t(k) = r(k) = 0

  old_r, r = (a,b)  # r0, r1
  old_s, s = (1,0)  # s0, s1
  old_t, t = (0,1)  # t0, t1

  while r != 0:
    q = old_r//r

    old_r, r = (r, old_r - q*r)
    old_s, s = (s, old_s - q*s)
    old_t, t = (t, old_t - q*t)
  
  return [old_s, old_t, old_r]
  

# GCD, LCM
A,B = map(int, input().split())

gcd = euclidean(A,B)
lcm = A*B // gcd
print(gcd)
print(lcm)

# Extended euclidean
print(*extended_euclidean(A,B))

# BOJ #3955
from math import ceil
SUP = 1000000000

T = int(input())
for i in range(T):
  K,C = map(int, input().split())
  res = extended_euclidean(K,C)

  if res[2] != 1:
    print("IMPOSSIBLE")
    continue

  s = res[0]
  t = res[1]
  l = max(ceil((1+s)/C), ceil((1-t)/K))
  if (t + K*l > SUP):
    print("IMPOSSIBLE")
    continue
  
  s = s - C*l
  t = t + K*l
  print(t)