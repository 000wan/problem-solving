#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 16;

int N;
int W[MAX_N][MAX_N];

int memo[MAX_N][1<<MAX_N];
int dp(int i, int visited) {
    if (visited == ((1<<N)-1)) {
        if (W[i][0] != INF)
            return W[i][0];
        return INF;
    }
    if (memo[i][visited] != -1)
        return memo[i][visited];
   
    int res = INF;
    for (int j = 0; j < N; ++j) {
        if (W[i][j] != INF && !(visited & (1<<j))) {
            res = min(res, W[i][j] + dp(j, visited | (1<<j)));
        }
    }
    memo[i][visited] = res;
    return memo[i][visited];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < (1<<N); ++k) {
            memo[i][k] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
            if (!W[i][j]) W[i][j] = INF;
        } 
    }

    cout << dp(0, 1) << '\n';

    return 0;
}
