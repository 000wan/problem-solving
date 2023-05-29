#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 6;

int N;
int w[MAX_N+1][MAX_N+1], e[MAX_N+1][MAX_N+1], root[MAX_N+1][MAX_N+1];
int optimal_bst(int N, int p[]) {
    for (int l = 1; l <= N; ++l) {
        for (int i = 1; i <= N-l+1; ++i) {
            int j = i+l-1;
            e[i][j] = INF;
            w[i][j] = w[i][j-1] + p[j];
            for (int r = i; r <= j; ++r) {
                int t = e[i][r-1] + e[r+1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    return e[1][N];
}

void sol(int i, int j) {
    if (i == j) {
        cout << i << ' ';
        return;
    }
    int r = root[i][j];
    cout << r << ' ';
    sol(i, r-1); sol(r+1, j);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    N = 5;
    int p[N+1] = {0, 10, 20, 15, 30, 25};

    cout << optimal_bst(N, p) << '\n';
    sol(1, N);
    
    return 0;
}