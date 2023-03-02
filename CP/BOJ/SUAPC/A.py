import sys
input = sys.stdin.readline

if __name__ == "__main__":
    times = []
    for t in range(8):
        time, team = input().split()
        tt = list(map(int, time.split(':')))
        times.append((tt[2] + 10**3 * tt[1] + 10**5 * tt[0], int(team == 'B')))
    times = sorted(times, key=lambda x: x[0])
    r, b = (0, 0)
    scores = [10, 8, 6, 5, 4, 3, 2, 1, 0]
    for rank in range(len(times)):
        if (times[rank][1] == 1):
            b += scores[rank]
        else:
            r += scores[rank]

    s = ["Red", "Blue"]
    if (r == b):
        print(s[times[0][1]])
    else:
        print(s[int(b > r)])

