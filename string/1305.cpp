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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    cin >> L;
    string s;
    cin >> s;

    auto pi = get_pi(s);
    int res = L-pi[L-1];
    cout << res << '\n';

    return 0;
}
