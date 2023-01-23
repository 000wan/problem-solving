#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int solve(int n, int S, int a[]) { 
    int res = INF;
    int i = 0, j = 0;
    int sum = a[i];
    while (i <= j && j < n) {
        if (sum >= S) {
            res = min(res, j-i+1);
            sum -= a[i++];
        }
        else
            sum += a[++j];
    }
    
    if (res == INF)
        return 0;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int a[N];
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    cout << solve(N, M, a) << '\n';

    return 0;
}
