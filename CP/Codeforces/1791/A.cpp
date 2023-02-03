#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s = "codeforces";
    std::unordered_map<char, bool> check;

    for (auto it : s) {
        check[it] = true;
    }

    int T;
    cin >> T;
    
    while (T--) {
        char x;
        cin >> x;
        if (check[x])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
