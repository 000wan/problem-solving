#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int n;
int a[100001];
bool visited[100001];
bool done[100001];
int cnt;

void dfs(int i) {
    visited[i] = true;
    if (!visited[a[i]])
        dfs(a[i]);
    else if (!done[a[i]]) {
        for (int j = a[i]; j != i; j = a[j]) {
            cnt ++;
        }
        cnt ++;
    }
    done[i] = true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        visited[i] = false;
        done[i] = false;
    }
    cnt = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    cout << n - cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
