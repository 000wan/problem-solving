#include <bits/stdc++.h>
#define ll long long
using namespace std;

// BOJ 15649
void solve(int N, int l, std::vector<int> v) {
    if (l == 0) {
        for (auto i = v.begin(); i != v.end(); ++i) {
            std::cout << *i << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; ++i) {
        if (find(v.begin(), v.end(), i) != v.end())
            continue;

        v.push_back(i);
        solve(N, l-1, v);
        v.pop_back();
    }
}

// BOJ 15650
void solve(int n, int N, int l, std::vector<int> v) {
    if (l == 0) {
        for (auto i = v.begin(); i != v.end(); ++i) {
            std::cout << *i << ' ';
        }
        cout << '\n';
    }
    if (n > N)
        return;

    for (int i = n; i <= N; ++i) {
        v.push_back(i);
        solve(i+1, N, l-1, v);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    std::vector<int> v;
    solve(1, N, M, v);

    return 0;
}
