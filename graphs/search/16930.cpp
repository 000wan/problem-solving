#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

pii id = {0,0};
const int MAX_N = 1000;
char a[MAX_N+1][MAX_N+1];
int N, M, K;
pii s, e;

int visited[MAX_N+1][MAX_N+1];
void bfs() {
    fill(&visited[0][0], &visited[N][M+1], INF);

    queue<pii> Q;
    Q.emplace(s);
    visited[s.first][s.second] = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while (!Q.empty()) {
        auto coor = Q.front();
        auto [x,y] = coor;
        Q.pop();
        int c = visited[x][y];

        if (coor == e) {
            cout << c << '\n';
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x, ny = y;
            for (int k = 1; k <= K; ++k) {
                nx += dx[i], ny += dy[i];
                if (1 > nx || nx > N || 1 > ny || ny > M)
                    break;
                if (a[nx][ny] == '#')
                    break;
                if (visited[nx][ny] <= c)
                    break;

                if (visited[nx][ny] != INF)
                    continue;
                visited[nx][ny] = c+1;
                Q.emplace(nx, ny);
            }
        }
    }

    cout << -1 << '\n';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N*M; ++i) {
        cin >> a[i/M+1][i%M+1];
    }
    auto& [x1, y1] = s;
    auto& [x2, y2] = e;
    cin >> x1 >> y1 >> x2 >> y2;

    bfs();

    return 0;
}
