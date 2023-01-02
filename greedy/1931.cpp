/* BOJ 1931 greedy algorithm */
#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
	int start;
	int stop;
};

bool cmp(Meeting i, Meeting j) {
	if (i.stop == j.stop)
		return i.start < j.start;
	return i.stop < j.stop;
}

int solve(int N, Meeting data[]) {
	sort(data, data+N, cmp);
	
	int prev = -1;
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (data[i].start >= prev) {
			prev = data[i].stop;
			res++;
		}
	}
	
	return res;
}

int main(void) {
	int N;
	cin >> N;
	
	Meeting data[100000];
	
	for (int i = 0; i < N; i++) {
		int start, stop;
		cin >> start >> stop;
		
		data[i].start = start;
		data[i].stop = stop;
	}
	
	cout << solve(N, data);
}

/* BOJ 1931 divide and conquer */
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
int info[100000][2];
unordered_map<int, vector<int>> table;

int solve(int start, int stop) {
	if (start >= stop)
		return 0;
	//cout << start << ' ' << stop <<'\n';
	
	int mid = (start+stop)/2;
	int res = solve(start, mid);
	if (mid > start)
		res += solve(mid, stop);
	
	vector<int>::iterator iter;
    for (iter = table[mid].begin(); iter != table[mid].end(); iter++) {
        int nstart = info[*iter][0];
        int nstop = info[*iter][1];
        
        if (nstart < mid && start <= nstart && nstop <= stop) {
        	int nres = 1 + solve(start, nstart) + solve(nstop, stop);
        	res = max(res, nres);
		}
    }
    
    return res;
}

int main(void) {
	cin >> N;
	
	int START = ~(1 << 31);
	int STOP = -1;
	for (int i = 0; i < N; i++) {
		int start, stop;
		cin >> start >> stop;
		
		START = min(START, start);
		STOP = max(STOP, stop);
		
		info[i][0] = start;
		info[i][1] = stop;
		
		for (int t = start; t < stop; t++) {
			table[t].push_back(i);
		}
	}
	
	cout << solve(START, STOP);
}
