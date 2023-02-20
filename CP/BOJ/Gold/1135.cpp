#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int n;
int parent[50];
vector<int> child[50];

int memo[50];
int dp(int i) {
    if (memo[i]) return memo[i];
    
    vector<int> a;
    for (auto& j : child[i]) {
        a.emplace_back(dp(j));
    }
    if (a.empty()) return memo[i] = 0;

    sort(a.begin(), a.end(), greater<int>());
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        res = max(res, a[i]+i+1);
    }
    return memo[i] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> parent[i];
        if (parent[i] != -1)
            child[parent[i]].emplace_back(i);
    }
    cout << dp(0) << '\n';


    return 0;
}
