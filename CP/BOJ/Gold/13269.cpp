#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int top[N][M], front[M], right[N];
    for (int i = 0; i < N*M; ++i) {
        cin >> top[i/M][i%M];
    }
    for (int i = 0; i < M; ++i)
        cin >> front[i];
    for (int i = 0; i < N; ++i) 
        cin >> right[N-1-i];

    int a[N][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (top[i][j] == 0)
                a[i][j] = 0;
            else
                a[i][j] = min(front[j], right[i]);
        }
    }

    for (int i = 0; i < N; ++i) {
        bool rflag = false;
        for (int j = 0; j < M; ++j) {
            rflag |= (a[i][j] == right[i]);
        }
        if (!rflag) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < M; ++i) {
        bool cflag = false;
        for (int j = 0; j < N; ++j) {
            cflag |= (a[j][i] == front[i]);
        }
        if (!cflag) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 0; i < N*M; ++i) {
        int r = i/M, c = i%M;
        cout << a[r][c] << " \n"[c == M-1];
    }

    return 0;
}
