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
    int l = get_pi(s)[n-1];

    if (n % (n-l))
        cout << 1 << '\n';
    else
        cout << n/(n-l) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (true) {
        cin >> s;
        if (s == ".") break;
        solve(s);
    }

    return 0;
}
