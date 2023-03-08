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

int kmp(string& s, string p) {
    int res = 0;
    auto pi = get_pi(p);

    int n = s.size(), m = p.size();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j])
            j = pi[j-1];
        if (s[i] == p[j]) {
            if (j == m-1) {
                res++;
                j = pi[j];
            }
            else j ++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    auto pi = get_pi(S);
    int n = S.size(), m = pi[n-1];   
    while (m > 0) {
        if (kmp(S, S.substr(0, m)) >= 3) {
            break;
        }
        m = pi[m-1];
    }

    if (m == 0)
        cout << -1 << '\n';
    else
        cout << S.substr(0, m) << '\n';

    return 0;
}

