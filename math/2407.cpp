#include <bits/stdc++.h>
#define ll long long
using namespace std;

class BigNumber {
	private:
		static const int MAX_LEN = 30;
		int digit[MAX_LEN]{ 0 };
		
	public:
		BigNumber() {}
		BigNumber(ll S) {
			int i = 0;
			while (i < MAX_LEN && S > 0) {
				digit[i++] = S % 10;
				S /= 10;
			}
		}
		BigNumber(string S) {
			int len = S.length();
			for(int i = 0; i < len; i++) {
				int k = (len-1) - i;
	            digit[i] = (int(S[k])-48);
			}
		}
		
		int at(int index);
		void set(ll S);
		static BigNumber add(BigNumber* a, BigNumber* b);
		void print();
};

int BigNumber::at(int index) {
	if (0 <= index && index < MAX_LEN)
		return digit[index];
	return 0;
}

void BigNumber::set(ll S) {
	int i = 0;
	while (i < MAX_LEN) {
		digit[i++] = S % 10;
		S /= 10;
	}
}

BigNumber BigNumber::add(BigNumber* a, BigNumber* b) {
	BigNumber res;
	int carry = 0;
	
    for(int i = 0; i < res.MAX_LEN; i++) {
        res.digit[i] = a->at(i) + b->at(i) + carry;
        carry = res.digit[i] / 10;
        res.digit[i] %= 10;
    }
    
    return res;
}

void BigNumber::print() {
	bool flag = true;
    for(int i = MAX_LEN-1; i >= 0; i--) {
        flag = flag && (digit[i] == 0);
        if (!flag) {
            cout << digit[i];
        }
    }
}

void solve(int N, int K) {
	BigNumber prev[N+1];
	
    for(int i=1; i<=N; i++) {
        BigNumber next[N+1];
        next[0].set(1);
		next[i].set(1);
        
        for(int j=1; j<=i-1; j++) {
            next[j] = BigNumber::add(&prev[j-1], &prev[j]);
        }
        
        for(int j=0; j<=i; j++) {
            prev[j] = next[j];
        }
    }
    
    prev[K].print();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
    int K;
    cin >> N >> K;
    
    solve(N, K);
	
	return 0;
}

