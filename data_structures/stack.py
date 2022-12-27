from collections import deque
import sys

N = int(input())
S = []
for i in range(N):
  inp = sys.stdin.readline().split()
  cmd = inp[0]

  if cmd == "push":
    S.append(int(inp[1]))
    continue
  if cmd == "pop":
    if len(S) == 0:
      print(-1)
    else:
      print(S.pop())
    continue
  if cmd == "size":
    print(len(S))
    continue
  if cmd == "empty":
    print(int(len(S) == 0))
    continue
  if cmd == "top":
    if len(S) == 0:
      print(-1)
    else:
      print(S[-1])
    continue