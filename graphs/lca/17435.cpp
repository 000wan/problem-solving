#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 2e5;
const int MAX_D = 20;
// table[i][j] : vertex after moving 2^j times from vertex i
int table[MAX_N+1][MAX_D];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> table[i][0];
    }

    for (int j = 1; j < MAX_D; ++j) {
        for (int i = 1; i <= N; ++i) {
            table[i][j] = table[table[i][j-1]][j-1];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int m, x;
        cin >> m >> x;
        for (int j = MAX_D-1; j >= 0; --j) {
            if (m & (1<<j)) {
                x = table[x][j];
            }
        }
        cout << x << '\n';
    }
    
    return 0;
}