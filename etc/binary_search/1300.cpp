#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, K;
bool check(int& S) {
    int res = 0, i, j;
    for (i = 1; i <= N; i = j+1) {
        if (S/i == 0) break;
        j = min(S/(S/i), N); // max j s.t. [N/j] = [N/i]
        res += min(S/i, N) * (j-i+1);
    }
    return res >= K;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    int lo = 0, hi = K, mid;
    while (lo+1 < hi) {
        mid = (lo+hi)/2;
        if (!check(mid)) lo = mid;
        else hi = mid;
    }
    cout << hi << '\n';

    return 0;
}
