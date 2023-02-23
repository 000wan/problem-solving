#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int N, C;
int x[200000];
bool check(int D) {
    int prev = x[0];
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (cnt == C) break;
        if (x[i]-prev >= D) {
            prev = x[i], cnt ++;
        }
    }
    return (cnt == C);
}

void solve() {
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }
    sort(x, x+N);

    ll low = 0, high = x[N-1]-x[0]+1;
    while (low+1 < high) {
        ll mid = (low+high)/2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
