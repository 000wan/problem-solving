def solve(S):
    if len(S) == 1:
        print(S, end='')
        return

    root = 0
    pr = []
    for i in range(len(S)):
        if len(pr) == 1 and i == len(S)-1:
            if pr[0] == 0:
                solve(S[1:-1])
                return

        if S[i] == '(':
            pr.append(i)
            continue
        if S[i] == ')':
            pr.pop()
            continue
        if len(pr) > 0:
            continue

        if (S[i] == '*' or S[i] == '/') and (S[root] != '+' and S[root] != '-'):
            root = i
        if S[i] == '+' or S[i] == '-':
            root = i
    
    solve(S[:root])
    solve(S[root+1:])
    print(S[root], end='')

S=input()
solve(S)
