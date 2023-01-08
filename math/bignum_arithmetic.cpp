#include <bits/stdc++.h>
#define ll long long
using namespace std;

class BigNumber {
	private:
		static const int MAX_LEN = 10001;
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

int main(void) {
	string A, B;
	cin >> A >> B;
	
	BigNumber a(A);
	BigNumber b(B);
	
	BigNumber res = BigNumber::add(&a, &b);
	res.print();
}
