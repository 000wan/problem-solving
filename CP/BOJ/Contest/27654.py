import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N,K = list(map(int, input().split()))
    a = []
    for i in range(N):
        a.append(list(map(int, input().split())))
    a = sorted(a, key=lambda x: x[0]/x[1], reverse=True)

    sp, sq = (0, 0)
    for i in range(K):
        sp += a[i][0]
        sq += a[i][1]
    print(sp/sq)
