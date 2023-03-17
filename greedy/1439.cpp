#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size(), x = 0, y = 0;
    s[n] = '2';
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[i+1]) {
            if (s[i] == '0') x++;
            else y++;
        }
    }
    cout << min(x,y) << '\n';

    return 0;
}
