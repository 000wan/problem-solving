#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    if (N%2 && M%2)
        cout << N*M-1 << '\n';
    else
        cout << N*M << '\n';

    return 0;
}
