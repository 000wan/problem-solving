#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N, W;
int a[1000][2];

int dist(int from, int to, int flag) {
    if (from >= 0)
        return abs(a[to][0]-a[from][0]) + abs(a[to][1]-a[from][1]);
    if (flag == 0) // police 1
        return abs(a[to][0]-1) + abs(a[to][1]-1);
    else
        return abs(a[to][0]-N) + abs(a[to][1]-N);
}

vector<vector<int>> memo(1001, vector<int>(1001, -1));
int selected[1001][1001];
int dp(int i, int j) {
    if (i == W || j == W)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    
    int res1 = INF;
    int res2 = INF;
    int next = max(i, j) + 1;
    res1 = dp(next, j) + dist(i-1, next-1, 0);
    res2 = dp(i, next) + dist(j-1, next-1, 1);

    if (res1 < res2) {
        memo[i][j] = res1;
        selected[i][j] = 1;
    } else {
        memo[i][j] = res2;
        selected[i][j] = 2;
    }
    
    return memo[i][j];
}

void solution(int i, int j) {
    if (i == W || j == W)
        return;
    cout << selected[i][j] << '\n';
    
    int next = max(i, j) + 1;
    if (selected[i][j] == 1)
        solution(next, j);
    else
        solution(i, next);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    
    for (int i = 0; i < W; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    cout << dp(0, 0) << '\n';
    solution(0, 0);

    return 0;
}
