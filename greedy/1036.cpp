#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int weight[36][51] = {};

bool cmp(int i, int j) {
	for(int d = 50; d >= 0; d--) {
		if (weight[i][d] > weight[j][d])
			return true;
		if (weight[i][d] < weight[j][d])
			return false;
	}
	return false;
}

char base36(int d) {
	char dd;
	if( d <= 9 ) {
		dd = (char)(d + 48);
	} else {
		dd = (char)(d-10 + 65);
	}
	
	return dd;
}

int base10(char d) {
	if( 48 <= int(d) && int(d) <= 57 ) {
		return (int(d)-48);
	} else {
		return (10 + int(d)-65);
	}
}

int main(void) {
	int N;
	int K;
	cin >> N;
	
	char S[50][51]; // numbers
	int y[36][51] = {}; // count of each number at each digit
	
	int m = 0;
	
	for(int i = 0; i < N; i++) {
		cin >> S[i];
		int j;
		for(j = 0; S[i][j] != '\0'; j++);
		reverse(S[i], S[i] + j);
		
		for(int j = 0; S[i][j] != '\0'; j++) {
			char c = S[i][j];
			y[base10(c)][j]++;
		}
		m = max(m, j);
	}
	
	cin >> K;
	
	// calc weight
	for(int x = 0; x < 36; x++) {
		for(int j = 0; j < 51; j++) {
			weight[x][j] = y[x][j] * (35 - x);
		}
	}
	
	// make weight to base36
	for(int x = 0; x < 36; x++) {
		int carry = 0;
		for(int j = 0; j < 51; j++) {
			weight[x][j] += carry;
			carry = weight[x][j] / 36;
			weight[x][j] %= 36;
		}
	}
	
	// sort indicies by weight
	int ind[36];
	for(int x = 0; x < 36; x++)
		ind[x] = x;
	sort(ind, ind+36, cmp);
	
	int map[36];
	for(int x = 0; x < 36; x++)
		map[ind[x]] = x;
		
	// calc sum
	string res = "";
	int carry = 0;
	
	for(int i = 0; i < m; i++) {
		int sum = carry;
		
		for(int x = 0; x < 36; x++) {
			int digit = x;
			if( map[digit] < K )
				digit = 35;
			
			sum += digit * y[x][i];
		}
		
		int d = sum%36;
		carry = sum/36;
		res.insert(res.begin(), base36(d));
	}
	while(carry > 0) {
		int d = carry%36;
		carry = carry/36;
		res.insert(res.begin(), base36(d));
	}
	
	cout << res;
}
