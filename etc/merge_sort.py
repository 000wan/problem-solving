def cmp(v, w):
  return v < w

def merge(a, tmp, start, mid, stop): # merge two sorted arrays
  i = start
  j = mid+1

  for k in range(start, stop+1):
    if i > mid:
      tmp[k] = a[j]
      j += 1
    elif j > stop:
      tmp[k] = a[i]
      i += 1
    elif cmp(a[j], a[i]): # j is strictly smaller than i
      tmp[k] = a[j]
      j += 1
    else:
      tmp[k] = a[i]
      i += 1
  for k in range(start, stop+1):
    a[k] = tmp[k]

def mergesort(a, tmp, start, stop):
  if start >= stop:
    return
  
  mid = (start + stop)//2
  mergesort(a, tmp, start, mid)
  mergesort(a, tmp, mid+1, stop)
  merge(a, tmp, start, mid, stop)

# BOJ 2751
import sys
N = int(input())
A = []
for i in range(N):
  A.append(int(sys.stdin.readline()))

mergesort(A, [None]*N, 0, N-1)
for i in range(N):
  print(A[i])

# 10814
import sys
N = int(input())
A = []
for i in range(N):
  age, name = sys.stdin.readline().split()
  age = int(age)
  A.append([age, name])

mergesort(A, [None]*N, 0, N-1)
for i in range(N):
  print(*A[i])