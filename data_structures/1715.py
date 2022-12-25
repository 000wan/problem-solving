import heapq
N = int(input())
data = []
for i in range(N):
  heapq.heappush(data, int(input()))

res = 0
while len(data) > 1:
  a = heapq.heappop(data)
  b = heapq.heappop(data)
  c = a + b
  
  heapq.heappush(data, c)
  res += c

print(res)