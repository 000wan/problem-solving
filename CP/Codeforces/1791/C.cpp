#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int i = 0, j = N-1;
    int res = N;
    while (i < j) {
        if ((S[i] == '0' && S[j] == '1') || (S[i] == '1' && S[j] == '0')) {
            i++, j--;
            res -= 2;
        }
        else
            break;
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
