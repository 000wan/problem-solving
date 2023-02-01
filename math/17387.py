import sys
input = sys.stdin.readline

def det(x1, y1, x2, y2):
    return (x1*y2 - x2*y1)
def dot(x1, y1, x2, y2):
    return (x1*x2 + y1*y2)

if __name__ == "__main__":
    x1,y1,x2,y2 = list(map(int, input().split()))
    x3,y3,x4,y4 = list(map(int, input().split()))
    
    d1 = det(x1, y1, x2, y2)
    d2 = det(x3, y3, x4, y4)
    
    dx1, dy1 = (x2-x1, y2-y1)
    dx2, dy2 = (x4-x3, y4-y3)
    D = det(dy1, -dx1, dy2, -dx2)
    
    # WLOG x1 <= x2
    if x1 > x2: x1,x2 = x2,x1
    if y1 > y2: y1,y2 = y2,y1
    if x3 > x4: x3,x4 = x4,x3
    if y3 > y4: y3,y4 = y4,y3
    
    if D == 0:
        if d1 == 0 and d2 == 0 and (x3 <= x2 and x1 <= x4) and (y3 <= y2 and y1 <= y4):
            print(1)
        else:
            print(0)
    else:
        a = dot(-dx2, dx1, d1, d2)
        b = dot(-dy2, dy1, d1, d2)
        if D < 0:
            a = -a
            b = -b
            D = -D
        
        if D*max(x1,x3) <= a <= D*min(x2,x4) and D*max(y1,y3) <= b <= D*min(y2,y4):
            print(1)
        else:
            print(0)
