#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int K, N;
    cin >> K >> N;
    
    int a[K];
    for (int i = 0; i < K; ++i) {
        cin >> a[i];
    }

    ll low = 0, high = (ll)(*max_element(a, a+K))+1, mid;
    while (low+1 < high) {
        mid = (low+high)/2;
        ll cnt = 0;
        for (int i = 0; i < K; ++i) {
            cnt += a[i]/mid;
        }

        if (cnt < N) {
            high = mid;
        }
        else if (cnt >= N) {
            low = mid;
        }
    }

    cout << low << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
