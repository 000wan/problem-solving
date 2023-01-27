#include <bits/stdc++.h>
using namespace std;

#define MAX_N 30
#define MAX_K 40000

int N;
int a[MAX_N];

char memo[MAX_N][MAX_N*MAX_K+1];
bool search(int i, int w) {
    if (w == 0)
        return true;
    if (i < 0)
        return false;
    if (memo[i][w])
        return memo[i][w] == 1;

    bool res = search(i-1, w);
    res = res || search(i-1, w + a[i]);
    res = res || search(i-1, abs(w - a[i]));

    if (res)
        memo[i][w] = 1;
    else
        memo[i][w] = -1;

    return res;
}



int main(void) {
    cin >> N;
    
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    int M;
    cin >> M;
    
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        
        if (search(N-1, x))
            cout << 'Y';
        else
            cout << 'N';
        cout << ' ';
    }
}
