#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    
    int res = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        res += K/a[i];
        K %= a[i];
    }
    
    cout << res;

    return 0;
}
