#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e4;
void solve() {
    int N;
    cin >> N;
    int par[N+1] = {}, color[N+1] = {};
    for (int i = 0; i < N-1; ++i) {
        int v, w;
        cin >> v >> w;
        par[w] = v;       
    }
    int v, w;
    cin >> v >> w;

    int p = v; par[0] = -1;
    while (par[p] != -1) {
        color[p] = 1; p = par[p];
    }
    p = w;
    while (!color[p]) {
        p = par[p];
    }
    cout << p << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}