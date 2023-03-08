#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

bool cmp(string& a, string& b) {
    return a.size() < b.size();
}

void solve() {
    int N;
    cin >> N;
    vector<string> a(2*N-2);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end(), cmp);

    string k = a[(N/2-1)*2+1];
    reverse(k.begin(), k.end());
    if (a[(N/2-1)*2] == k)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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
