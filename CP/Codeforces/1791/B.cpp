#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    pair<int, int> coor = {0, 0};
    for (auto it : S) {
        switch (it) {
            case 'R':
                coor.first ++;
                break;
            case 'L':
                coor.first --;
                break;
            case 'U':
                coor.second ++;
                break;
            case 'D':
                coor.second --;
                break;
        }
        if (coor.first == 1 && coor.second == 1) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
    return;
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
