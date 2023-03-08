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

const int MAX_A = 360000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    string a (2*MAX_A, '0');
    string b (MAX_A, '0');
    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        a[x] = a[MAX_A+x] = '1';
    }
    for (int x, i = 0; i < N; ++i) {
        cin >> x;
        b[x] = '1';
    }

    auto res = kmp(a, b);
    if (!res.empty()) {
        cout << "possible" << '\n';
    } else {
        cout << "impossible" << '\n';
    }

    return 0;
}

