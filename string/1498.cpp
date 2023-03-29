#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

vector<int> get_pi(string& p) {
    int m = p.size();
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

void solve(string& s) {
    int n = s.size();
    auto pi = get_pi(s);
    for (int i = 1; i <= n; ++i) {
        int l = pi[i-1];
        if (i % (i-l) == 0 && i/(i-l) != 1)
            cout << i << ' ' << i/(i-l) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t = 0;
    while (true) {
        cin >> n;
        if (!n) break;
        string s;
        cin >> s;
        cout << "Test case #"<<++t << '\n';
        solve(s);
        cout << '\n';
    }

    return 0;
}
