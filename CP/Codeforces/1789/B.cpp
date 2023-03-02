#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
 
void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    
    int i = 0, j = N-1;
    bool res = true, flag = false;
    while (i < j && s[i] == s[j])
        i++, j--;
    while (i < j) {
        if (flag && s[i] != s[j]) {
            res = false;
            break;
        }
        if (s[i] == s[j])
            flag = true;
        i++, j--;
    }
 
    cout << (res ? "YES" : "NO") << '\n';
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
