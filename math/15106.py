
def SOD(n):
    res = 0;
    i = 1
    j = 1

    while i <= n:
        j = n//(n//i)
        res += (n//i) * (((i+j) * (j-i+1)) // 2)
        i = j+1

    return res

a, b = map(int, input().split())
print(SOD(b) - SOD(a-1))
