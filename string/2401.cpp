#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

const int MAX_N = 500;
const int MAX_M = 1e5;
bool A[MAX_M][MAX_N];
int lens[MAX_N];
int N, M;

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

void kmp(int ind, string& s, string& p) {
    auto pi = get_pi(p);

    int n = s.size(), m = p.size();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j])
            j = pi[j-1];
        if (s[i] == p[j]) {
            if (j == m-1) {
                A[i-m+1][ind] = true;
                j = pi[j];
            }
            else j ++;
        }
    }
}

int memo[MAX_M];
int dp(int i) {
    if (i >= M)
        return 0;

    int& res = memo[i];
    if (res != -1)
        return res;

    res = dp(i+1);
    for (int j = 0; j < N; ++j) {
        if (A[i][j])
            res = max(res, lens[j]+dp(i+lens[j]));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string T;
    cin >> T;
    M = T.size();
    fill_n(memo, M, -1);

    cin >> N;

    string x;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        kmp(i, T, x);
        lens[i] = x.size();
    }
    cout << dp(0) << '\n';


    return 0;
}

