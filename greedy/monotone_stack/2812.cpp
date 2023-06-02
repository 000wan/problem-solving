#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
#define pii pair<int,int>

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int N, k;
    cin >> N >> k;
    string s;
    cin >> s;

    vector<int> st;
    for (int i = 0; i < N; ++i) {
        int x = s[i]-'0';
        while (k > 0 && !st.empty() && x > st.back()) {
            st.pop_back(); k--;
        }
        st.push_back(x);
    }
    for (int i = 0; i < st.size()-k; ++i) {
        cout << st[i];
    }
    
    return 0;
}