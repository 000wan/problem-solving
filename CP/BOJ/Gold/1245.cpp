#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, M;
int h[100][70];
bool visited[100][70];
bool dfs(int x, int y) {
    visited[x][y] = true;

    bool flag = true;
    for (int i = 0; i < 8; ++i) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        if (h[nx][ny] > h[x][y]) {
            flag = false;
        }
        else if (h[nx][ny] == h[x][y]) {
            if (!visited[nx][ny])
                flag = dfs(nx,ny) && flag;
        }
    }
    return flag;
}


void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> h[i][j];
        }
    }

    int res = 0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < M; ++y) {
            if (visited[x][y]) continue;
            if (dfs(x,y)) {
                res ++;
            }
        }
    }
    cout << res << '\n';
}

bool test() {
    cout << "hi" << '\n';
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
