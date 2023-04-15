#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S; cin >> S;
    string p; cin >> p;
    string st;
    int n = S.size(), m = p.size();
    for (int i = 0; i < n; ++i) {
        st += S[i];
        int l = st.size();
        if (l >= m) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                flag &= st[l-m+j] == p[j];
            }
            if (flag) {
                for (int j = 0; j < m; ++j) {
                    st.pop_back();
                }
            }
        }
    }
    cout << (st.empty() ? "FRULA" : st) << '\n';
    
    return 0;
}