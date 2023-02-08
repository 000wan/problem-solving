#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 10;

int hi[MAX_N], si[MAX_N];

ll dp[MAX_N][MAX_M+1]; 
ll weight[MAX_N][MAX_N];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        weight[i][i] = si[i];
        int maxj = i;

        for (int j = i+1; j < n; j++) {
            if (hi[j] > hi[maxj]) {
                weight[i][j] = si[j];
                maxj = j;
            }
            else if (hi[j] == hi[maxj]) {
                weight[i][j] = si[j] + weight[i][maxj];
                maxj = j;
            }
            else
                weight[i][j] = weight[i][maxj];
        } 
    }
}

ll search(int i, int m) {
    if (dp[i][m] != -1)
        return dp[i][m];
    if (m == 1)
        return weight[0][i];

    ll res = INT_MIN;
    for (int k = 1; k <= i; ++k) {
        res = max(res, search(k-1, m-1) + weight[k][i]);
    }
    
    //cout << "dp: "<< i << ' '<< m << " : "<<res << '\n';
    dp[i][m] = res;
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
    
    init(N);
    cout << search(N-1, M);

    return 0;
}
