#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int a[N+2];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    a[N] = a[N+1] = 0;

    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i+1] <= a[i+2]) {
            int d = min(a[i], min(a[i+1], a[i+2]));
            a[i] -= d, a[i+1] -= d, a[i+2] -= d;
            res += 7*d;
            
            d = min(a[i], a[i+1]);
            a[i] -= d, a[i+1] -= d;
            res += 5*d;
        } else {
            int d = min(a[i], a[i+1]-a[i+2]);
            a[i] -= d, a[i+1] -= d;
            res += 5*d;
            
            d = min(a[i], min(a[i+1], a[i+2]));
            a[i] -= d, a[i+1] -= d, a[i+2] -= d;
            res += 7*d;
        }
        res += 3*a[i]; a[i] = 0;
    }
    cout << res << '\n';
    
    return 0;
}