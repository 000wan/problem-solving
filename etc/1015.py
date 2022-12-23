N = int(input())
A = list(map(int, input().split()))

def swap(a, b, arr):
  temp = arr[a]
  arr[a] = arr[b]
  arr[b] = temp

def insertion_sort(arr, N):
  for i in range(N):
    j = i-1
    while j >= 0:
      if arr[j] > arr[j+1]:
        swap(j, j+1, arr)
      j -= 1
  
  return arr

P0 = [[] for i in range(1001)]
for i in range(N):
  P0[A[i]].append(i)

A = insertion_sort(A, N)

P1 = [[] for i in range(1001)]
for i in range(N):
  P1[A[i]].append(i)

P = [0 for i in range(N)]
for e in A:
  P[P0[e][0]] = P1[e][0]
  del P0[e][0]
  del P1[e][0]
  
for e in P:
  print(e, end=' ')