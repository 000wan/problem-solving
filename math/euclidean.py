A,B = map(int, input().split())

m,n = A,B
if m < n:
  m,n = n,m
while n != 0:
  t = m%n
  m,n = n,t

gcd = m
lcm = A*B // gcd
print(gcd)
print(lcm)