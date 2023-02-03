#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    std::unordered_map<char, int> cnt;
    for (auto it : S) {
        cnt[it] ++;
    }
    
    std::unordered_map<char, int> selected;
    int curr = cnt.size();
    int res = curr;
    for (auto it : S) {
        if (cnt[it] >= 2) {
            if (selected[it] == 0) {
                curr ++;
            }
            else if (selected[it] == cnt[it]-1) {
                curr --;
            }
            
            selected[it] ++;
            res = max(res, curr);
        }
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
