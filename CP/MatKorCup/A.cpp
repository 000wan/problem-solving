#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    if (12 <= N && N <= 16 && M == 0)
        cout << 320 << '\n';
    else
        cout << 280 << '\n';

    return 0;
}
