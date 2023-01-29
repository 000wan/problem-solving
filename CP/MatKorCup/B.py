import sys
input = sys.stdin.readline

def gcd(m,n):
    while n != 0:
        t=m%n
        m,n=n,t
    return m

if __name__ == "__main__":
    n,b = list(map(int, input().split()))
    sumx, sumy = (0,0)
    for i in range(n):
        x,y = list(map(int, input().split()))
        sumx += x
        sumy += y-b

    if sumx == 0:
        print("EZPZ")
    else:
        g=gcd(sumx, sumy)
        p,q=(sumy//g, sumx//g)
        sign=""
        if p*q<0: sign="-"
        p,q=(abs(p), abs(q))
        
        if q == 1:
            print(sign+str(p))
        else:
            print(sign+str(p)+"/"+str(q))
