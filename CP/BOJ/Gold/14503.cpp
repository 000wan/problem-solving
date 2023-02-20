#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N, M;
int a[50][50];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt;
bool visited[50][50];
void search(int i, int j, int d) {
    if (!visited[i][j]) {
        visited[i][j] = true, cnt ++;
    }
    for (int k = 0; k < 4; ++k) {
        int nd = (4+d-k-1)%4;
        int ni = i + dx[nd], nj = j + dy[nd];
        if (0 <= ni && ni < N && 0 <= nj && nj < M) {
            if (a[ni][nj] == 0 && !visited[ni][nj]) {
                search(ni, nj, nd);
                return;
            }
        }
    }
    
    int nd = (d+2)%4;
    int ni = i + dx[nd], nj = j + dy[nd];
    if (0 <= ni && ni < N && 0 <= nj && nj < M) {
        if (a[ni][nj] == 0) search(ni, nj, d);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }

    search(r, c, d);
    cout << cnt << '\n';

    return 0;
}
