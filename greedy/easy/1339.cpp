#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    ll cnt[26] = {};
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = s.size()-1, base = 1; j >= 0; --j) {
            cnt[s[j]-'A'] += base;
            base *= 10;
        }
    }
    sort(cnt, cnt+26, greater<int>());

    ll res = 0;
    for (int i = 0; i < 10; ++i) {
        res += cnt[i]*(9-i);
    }
    cout << res << '\n';
    
    return 0;
}