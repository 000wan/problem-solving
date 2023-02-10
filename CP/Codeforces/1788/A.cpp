#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 2) a.emplace_back(i);
    }
    
    int len = a.size();
    if (len == 0)
        cout << 1 << '\n';
    else if (len%2)
        cout << -1 << '\n';
    else {
        cout << 1+a[len/2-1] << '\n';
    }
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
