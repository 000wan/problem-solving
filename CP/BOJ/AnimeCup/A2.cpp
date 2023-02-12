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
    
    int r = 0, c = 0;
    int mini = INF, minj = INF;
    for (int i = 1; i < N; ++i) {
        int x;
        cin >> x;
        if (x < mini) {
            r = i;
            mini = x;
        }
    }
    for (int j = 1; j <= M; ++j) {
        int x;
        cin >> x;
        if (j == 1 && x < mini) {
            r = N;
            mini = x;
        }
        if (x < minj) {
            c = j;
            minj = x;
        }
    }
    cout << r << ' ' << c << '\n';

    return 0;
}
