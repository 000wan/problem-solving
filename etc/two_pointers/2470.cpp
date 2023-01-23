#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

void solve(int n, int a[]) {
    sort(a, a+n);

    int m = 2*INF+1;
    int i = 0, j = n-1;
    int sol[2];
    while (i < j) {
     if (abs(a[i] + a[j]) < m) {
         m = abs(a[i] + a[j]);
         sol[0] = i;
         sol[1] = j;
     }
     
     if (a[i] + a[j] > 0)
         j--;
     else
         i++;
    }

    cout << a[sol[0]] << ' ' << a[sol[1]];
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

    solve(N, a);

    return 0;
}
