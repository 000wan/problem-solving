#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;

vector<string> split(string str, char Delimiter) {
    if (str == "") return vector<string>();
    istringstream iss(str);
    string buffer;
 
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
    return result;
}

void solve() {
    string s;
    cin >> s;
    int N;
    cin >> N;
    
    string x;
    std::deque<int> a;
    cin >> x;
    x = x.substr(1, x.size()-2);
    for (auto& i : split(x,',')) {
        a.emplace_back(stoi(i));
    }

    bool front = true;
    for (auto &S : s) {
        if (S == 'R') {
            front = !front;
        } else {
            if (a.empty()) {
                cout << "error" << '\n';
                return;
            }
            if (front) a.pop_front();
            else a.pop_back();
        }
    }
    
    cout << '[';
    while (!a.empty()) {
        int x = front ? a.front() : a.back();
        front ? a.pop_front() : a.pop_back();
        cout << x;
        if (!a.empty()) cout << ',';
    }
    cout << "]\n";
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
