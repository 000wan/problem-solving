import sys
input = sys.stdin.readline

def cross_prod(v, w):
    return (v[0]*w[1]-v[1]*w[0])

if __name__ == "__main__":
    N = int(input())
    res = 0
    first = list(map(int, input().split()))
    prev = first
    for i in range(N-1):
        inp = list(map(int, input().split()))
        res += cross_prod(prev, inp)
        prev = inp
    res += cross_prod(prev, first)
    res = round(abs(res)*0.5, 1)
    print(res)
