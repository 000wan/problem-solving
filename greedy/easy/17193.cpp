#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    cin >> N >> K;
    
    cout << 2019201997 - 12*(7*(K-1)+4*N) << '\n';
    
    return 0;
}