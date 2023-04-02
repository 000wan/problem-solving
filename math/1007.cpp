#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <math.h>
#define ll long long
using namespace std;
const int INF = 1e9;

#define pii pair<int,int>
int N;
vector<pii> a;

double res = INF;
bool visited[20];
double suml() {
    pii ret = {0, 0};
    for (int i = 0; i < N; ++i) {
        int sign = visited[i] ? 1 : -1;
        ret.first += sign * a[i].first;
        ret.second += sign * a[i].second;
    }
    return sqrt(pow(ret.first, 2) + pow(ret.second, 2));
}

void search(int i, int cnt) {
    if (cnt == N/2) {
        res = min(res, suml());
        return;
    }
    if (i == N) return;

    visited[i] = 1; search(i+1, cnt+1);
    visited[i] = 0; search(i+1, cnt);
}

void solve() {
    cin >> N;
    fill(&visited[0], &visited[N], 0);
    res = INF;
    
    a = vector<pii>(N);
    for (auto& [x, y] : a) {
        cin >> x >> y;
    }
    search(0, 0);
    printf("%f\n", res);
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