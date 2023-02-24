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

vector<int> kmp(string& s, string& p) {
    vector<int> res;
    auto pi = get_pi(p);

    int n = s.size(), m = p.size();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j])
            j = pi[j-1];
        if (s[i] == p[j]) {
            if (j == m-1) {
                res.emplace_back(i-m+1);
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

    string T, P;
    getline(cin, T), getline(cin, P);

    auto res = kmp(T, P);
    cout << (int)res.size() << '\n';
    for (auto& i : res) {
        cout << i+1 << '\n';
    }

    return 0;
}
