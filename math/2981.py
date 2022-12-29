N = int(input())

def gcd(A,B):
    m,n = A,B
    if m < n:
      m,n = n,m
    while n != 0:
      t = m%n
      m,n = n,t
    return m

nums = []
prev = 0
for t in range(N):
    n = int(input())
    if t>0:
        nums.append(abs(n-prev))
    prev = n

g = nums[0]
for i in range(N-1):
    g = gcd(g, nums[i])

for a in range(2, g+1):
    if g%a == 0:
        print(a)