#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10;

int hi[MAX_N], si[MAX_N];

ll dp[MAX_N][MAX_M+1]; 
int visited[MAX_N][MAX_M+1][2]; // 0: latest index, 1: power sum

ll search(int i, int m) {
    if (i < 0)
        return 0;
    if (dp[i][m] != -1)
        return dp[i][m];
    
    ll res1 = 0;
    if (m > 0)
        res1 = search(i-1, m-1) + si[i];
    
    ll res2 = 0;
    int j;
    if (i >= m) {
        res2 = search(i-1, m);
        j = visited[i-1][m][0];
        visited[i][m][1] = visited[i-1][m][1];

        if (hi[j] < hi[i]) {
            res2 += si[i] - visited[i-1][m][1];
            visited[i][m][1] = si[i];
            j = i;
        }
        else if (hi[j] == hi[i]) {
            res2 += si[i];
            visited[i][m][1] += si[i];
            j = i;
        }
    }
    //cout <<i<<' '<<m<<" : "<< res1 << ' ' << res2 << '\n';
    if (res1 > res2) {
        visited[i][m][0] = i;
        visited[i][m][1] = si[i];
        dp[i][m] = res1;
    } else {
        visited[i][m][0] = j;
        dp[i][m] = res2;
    }
    return dp[i][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> hi[i] >> si[i];
    }
    
    cout << search(N-1, M-1);

    return 0;
}
