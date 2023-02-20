#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9;
const int MAX_N = 1e7;

int len = 7;
int num[5] = {3, 2, 0, 2, INF};

char S[] = "0000000";
vector<int> sol;
void search(int i, int cnt) {
    if (i == -1) {
        if (cnt == 4) {
            sol.emplace_back(stoi(S));
        }
        return;
    }
    if (4-cnt > i+1)
        return;
    
    int c;
    for (int x = 0; x < 10; ++x) {
        c = cnt;
        if (x == num[cnt]) c = cnt+1;
        S[i] = x + '0';
        search(i-1, c);
        S[i] = '0';
    }
}

void init() {
    search(len-1, 0);
    sort(sol.begin(), sol.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    int N;
    cin >> N;
    int i = lower_bound(sol.begin(), sol.end(), N) - sol.begin();
    if (sol[i] == N)
        cout << i+1 << '\n';
    else
        cout << i << '\n';

    return 0;
}
