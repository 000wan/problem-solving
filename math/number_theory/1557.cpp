#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 1e9;
const int SQRT_N = 50000;

int sign[SQRT_N+1];
void init() {
    sign[1] = 1;
    for (int i = 2; i <= SQRT_N; ++i) {
        int m = i, p = 0, flag = 1;

        for (int j = 2; j*j <= m; ++j) {
            if (m%j) continue;

            int cnt = 0; p++;
            while (m%j == 0) {
                m /= j; cnt++;
            }
            flag &= cnt <= 1;
        }

        if (flag) {
            sign[i] = (p%2 ? 1 : -1);
        } else {
            sign[i] = 0;
        }
    }
}

int N;
bool check(ll n) {
    ll sum = 0;
    for (int i = 1; i*i <= n; ++i) {
        sum += sign[i] * (n/(i*i));
    }
    return sum < N;
}

void solve() {
    cin >> N;
    
    ll lo = 0, hi = 2*N;
    while (lo+1 < hi) {
        int mid = (lo+hi)/2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << hi << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    init();
    solve();   
    
    return 0;
}