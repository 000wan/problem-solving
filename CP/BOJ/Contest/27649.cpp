#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);

    vector<char> tk {'<','>','&','|','(',')',' '};
    vector<string> res;
    for (int i = 0, prev = 0; i <= (int)s.size(); ++i) {
        if (i == (int)s.size()) {
            res.push_back(s.substr(prev, i-prev));
            break;
        }

        for (auto& t : tk) {
            if (s[i] != t) continue;
            res.push_back(s.substr(prev, i-prev));

            if (t == '&' || t == '|') {
                res.push_back(s.substr(i++, 2));
            }
            else if (t != ' ') {
                res.push_back(s.substr(i, 1));
            }
            prev = i+1;
            break;
        }
    }

    for (auto& r: res)
        if (r != "")
            cout << r << ' ';

    return 0;
}
