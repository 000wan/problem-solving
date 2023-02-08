#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int N) {
	map<int,int> s;
	
	for(int i = 0; i < N; i++) {
		int d, t;
		cin >> d >> t;
		s[d] += t;
	}
	
	map <int,int>::iterator it;
	int res = 0;
	int prev = 0;
	int left = 0;
	int right = 0;
	
    for(it = s.begin(); it != s.end() ; it++) {
    	int ti = it->second;
        int delta = it->first - prev;
        
		for(int i = prev + 1; i <= it->first; i++) {
    		if ((i % 7) != 6 && (i % 7) != 0 )
    			left ++;
    	}
		right += delta;
		
		if (ti <= left) {
			left -= ti;
		}
		else if (ti <= left + right) {
			right -= (ti - left);
			res += (ti - left);
			left = 0;
		}
		else {
			res = -1;
			break;
		}
		
        prev = it->first;
    }
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	
	cout << solve(N);
	
	return 0;
}

