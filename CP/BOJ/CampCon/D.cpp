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
    
    std::deque<char> dq;
    std::deque<int> order;
    for (int i = 0; i < N; ++i) {
        int flag;
        cin >> flag;
    
        if (flag == 3) {
            if (dq.empty()) continue;
            if (order.front() > order.back()) {
                dq.pop_front();   
                order.pop_front();
            }
            else {
                dq.pop_back();
                order.pop_back();
            } 
        } else {
            char x;
            cin >> x;
            if (flag == 1) {
                dq.push_back(x);
                order.push_back(i);
            }
            else if (flag == 2) {
                dq.push_front(x);
                order.push_front(i);
            }
        }
    }
    if (dq.empty())
        cout << 0 << '\n';
    else {
        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
    }

    return 0;
}
