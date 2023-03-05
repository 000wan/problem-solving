#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 1e3;

int K[MAX_N], sum[MAX_N+1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, U, V;
    cin >> N >> Q >> U >> V;
    for (int i = 0; i < N; ++i) {
        cin >> K[i];
        sum[i+1] = K[i] + sum[i];
    }

    int c, a, b;
    while (Q--) {
        cin >> c >> a >> b;
        a--, b--;
        if (c == 0) {
            int fi = INF, res = -INF;
            for (int i = a; i <= b; ++i) {
                fi = min(fi, U*sum[i]+V*(i-1));
                res = max(res, U*sum[i+1]+V*i - fi);
            }
            cout << res-V << '\n';
        } else {
            K[a] = b+1;
            for (int i = 0; i < N; ++i) {
                sum[i+1] = K[i] + sum[i];
            }
        }
    }

    return 0;
}
