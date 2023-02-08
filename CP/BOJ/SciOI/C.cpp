#include <bits/stdc++.h>
using namespace std;

#define SUP 998244353

long long int solve(int Xi, unordered_map<int,int> table, int x, int y) {	
	long long int res = 0;
	for(auto j : table) {
    	int Xj = j.first;
    	int cj = j.second;
    	
    	if (Xi >= Xj) // don't need to pay
    		continue;
    	
    	int term = 1 + abs(Xj - Xi)/x;
    	res += cj * term;
    	res %= SUP;
    }
    
    res = (y * res) % SUP;
    return res;
}

int main(void) {
	int N, x, y;
	cin >> N >> x >> y;
	
	int first;
	unordered_map<int,int> table;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        table[X]++;
        
        if (i == 0)
        	first = X;
    }
    
    long long int res = 0;
    for(auto i : table) {
    	int Xi = i.first;
    	int ci = i.second;
    	
    	res += ci * solve(Xi, table, x, y);
    	res %= SUP;
    }
    
    cout << res << ' ' << solve(first, table, x, y);
}
