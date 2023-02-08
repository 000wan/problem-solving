#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int N, int a[]) {
    int res = a[0];
    for (int i = 1, j = N-1; i < j; i++, j--) {
        res += a[i] - a[j];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N, greater<int>());

    cout << solve(N, a);

    return 0;
}
