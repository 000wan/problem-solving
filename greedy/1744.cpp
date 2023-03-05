#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    std::priority_queue<int, vector<int>, greater<int>> minus;
    std::priority_queue<int> plus;
    while (N--) {
        int x;
        cin >> x;
        if (x > 0) plus.emplace(x);
        else minus.emplace(x);
    }

    int res = 0;
    while (!minus.empty()) {
        if (minus.size() == 1) {
            res += minus.top();
            minus.pop();
        }
        else {
            auto x = minus.top();
            minus.pop();
            auto y = minus.top();
            minus.pop();
            res += x*y;
        }
    }
    while (!plus.empty()) {
        if (plus.size() == 1) {
            res += plus.top();
            plus.pop();
        }
        else {
            auto x = plus.top();
            plus.pop();
            auto y = plus.top();
            plus.pop();
            if (x > 1 && y > 1)
                res += x*y;
            else res += x+y;
        }
    }
    cout << res << '\n';

    return 0;
}
