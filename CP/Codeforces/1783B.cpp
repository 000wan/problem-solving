#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int a[n][n];
    int i = 0, j = 0, sign = 1;
    int l = n*n, r = 1;
    while (i < n) {
        if ((i+j)%2 == 0) {
            a[i][j] = l--;
        } else {
            a[i][j] = r++;
        }
        j += sign;
        if (j >= n || j < 0) {
            j -= sign;
            i ++;
            sign *= -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " \n"[j == n-1];
        }
    }
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
