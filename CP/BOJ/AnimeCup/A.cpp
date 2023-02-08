#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;
    
    int a = 0, b = 0, c = 0;
    for (; a < S.size(); ++a) {
        if (S[a] == ':')
            b++;
        if (S[a] == '_')
            c++;
    }
    cout << a+b+5*c << '\n';

    return 0;
}
