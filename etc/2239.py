import sys
input = sys.stdin.readline

A = []
rvis = [[False for __ in range(10)] for _ in range(9)] # first: row, second: number
cvis = [[False for __ in range(10)] for _ in range(9)]
bvis = [[False for __ in range(10)] for _ in range(9)]

def bind(i, j):
    return (3*(i//3)+j//3)

def init():
    for i in range(9):
        for j in range(9):
            rvis[i][A[i][j]] = True
            cvis[j][A[i][j]] = True
            bvis[bind(i,j)][A[i][j]] = True

flag = False
def search(i, j):
    global flag
    if i == 9:
        for i in range(9):
            for j in range(9):
                print(A[i][j], end='')
            print()
        flag = True
        return

    if A[i][j] == 0:
        for t in range(1, 10):
            if flag:
                return
            if rvis[i][t] or cvis[j][t] or bvis[bind(i,j)][t]:
                continue

            A[i][j] = t
            rvis[i][t] = cvis[j][t] = bvis[bind(i,j)][t] = True
            if j+1 < 9:
                search(i, j+1)
            else:
                search(i+1, 0)
            A[i][j] = 0
            rvis[i][t] = cvis[j][t] = bvis[bind(i,j)][t] = False
    else:
        if j+1 < 9:
            search(i, j+1)
        else:
            search(i+1, 0)
    return

if __name__ == "__main__":
    for i in range(9): 
        A.append(list(map(int, list(input().strip()))))
    init()
    search(0, 0)
    
