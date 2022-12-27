from collections import deque
import sys

N = int(input())
Q = deque()
for i in range(N):
  inp = sys.stdin.readline().split()
  cmd = inp[0]

  if cmd == "push_front":
    Q.appendleft(int(inp[1]))
    continue
  if cmd == "push_back":
    Q.append(int(inp[1]))
    continue
  if cmd == "pop_front":
    if len(Q) == 0:
      print(-1)
    else:
      print(Q.popleft())
    continue
  if cmd == "pop_back":
    if len(Q) == 0:
      print(-1)
    else:
      print(Q.pop())
    continue
  if cmd == "size":
    print(len(Q))
    continue
  if cmd == "empty":
    print(int(len(Q) == 0))
    continue
  if cmd == "front":
    if len(Q) == 0:
      print(-1)
    else:
      print(Q[0])
    continue
  if cmd == "back":
    if len(Q) == 0:
      print(-1)
    else:
      print(Q[-1])
    continue