#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

string S;
int M;

int sti(string s) {
    if (s.size())
        return stoi(s);
    return 0;
}

ll count(char num) {
    ll ret = 0, a;
    for (int i = 0; i < M; ++i) {
        if (i == 0 && num == '0')
            continue;
        a = (sti(S.substr(0, i)) - (int)(num == '0')) * pow(10, M-i-1);
        if (num < S[i])
            a += pow(10, M-i-1);
        else if (num == S[i]) 
            a += sti(S.substr(i+1, M-i-1)) + 1;

        ret += a;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S;
    M = S.size();
    for (char i = '0'; i <= '9'; ++i) {
        cout << count(i) << ' ';
    }

    return 0;
}
