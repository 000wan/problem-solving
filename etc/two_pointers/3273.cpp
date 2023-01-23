#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int n, int x, int a[]) {
    sort(a, a+n);

    int cnt = 0;
    int i = 0, j = n-1;
    while (i < j) {
     if (a[i] + a[j] == x) {
         cnt++;
         i++;
     }
     else if (a[i] + a[j] < x)
         i++;
     else
         j--;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    int M;
    cin >> M;

    cout << solve(N, M, a) << '\n';

    return 0;
}
