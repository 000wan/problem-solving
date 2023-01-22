#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 14;

ll nqueens = 0;
bool rvis[MAX_N] = {};
bool cvis[MAX_N] = {};
bool uvis[2*MAX_N-1] = {};
bool dvis[2*MAX_N-1] = {};

void NQueen(int i, int cnt, int N) {
    if (cnt == 0) {
        nqueens++;
        return;
    }
    if (i >= N)
        return;

    //cout << i << ' ' << j << '\n';
    for (int j = 0; j < N; j++) {
        if (!rvis[i] && !cvis[j] && !uvis[i+j] && !dvis[N-1+i-j]) {
            rvis[i] = cvis[j] = uvis[i+j] = dvis[N-1+i-j] = true;
            NQueen(i+1, cnt-1, N);
            rvis[i] = cvis[j] = uvis[i+j] = dvis[N-1+i-j] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    NQueen(0, N, N); 
    cout << nqueens << '\n';

    return 0;
}
