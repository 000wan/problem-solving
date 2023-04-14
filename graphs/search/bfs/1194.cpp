#include <bits/stdc++.h>
#include <queue>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char a[50][50];
bool visited[50][50][1<<6];

void solve() {
    int N, M;
    cin >> N >> M;
    pii start;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '0')
                start = {i, j};
        }
    }

    queue<pii> q;
    queue<int> cnt, items;
    q.emplace(start); cnt.emplace(0); items.emplace(0);
    visited[start.first][start.second][0] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        auto c = cnt.front();
        auto item = items.front();
        q.pop(); cnt.pop(); items.pop();

        // cout << x << ' ' << y << '\n';

        if (a[x][y] == '1') {
            cout << c << '\n';
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visited[nx][ny][item]) continue;
            if (a[nx][ny] == '#') continue;

            int nitem = item;
            if ('A' <= a[nx][ny] && a[nx][ny] <= 'F') {
                int ni = a[nx][ny]-'A';
                if (!(item & (1<<ni))) continue;
            }
            if ('a' <= a[nx][ny] && a[nx][ny] <= 'z') {
                int ni = a[nx][ny]-'a';
                nitem = item | (1<<ni);
            }

            q.emplace(nx, ny);
            cnt.emplace(c+1);
            items.emplace(nitem);
            visited[nx][ny][item] = 1;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}