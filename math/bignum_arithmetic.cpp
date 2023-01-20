#include <bits/stdc++.h>
#define ll long long
using namespace std;

class BigNumber {
	private:
		static const int MAX_LEN = 10001;
		int digit[MAX_LEN + 1]{ 0 }; // last index for sign (0, -1)
		
	public:
		BigNumber() {}
		BigNumber(ll S) {	
            if (S < 0) {
                set_sign(-1);
                S *= -1;
            }
            int i = 0;
			while (i < MAX_LEN && S > 0) {
				digit[i++] = S % 10;
				S /= 10;
			}
		}
		BigNumber(string S) {
            if (S[0] == '-') {
                set_sign(-1);
                S.erase(0, 1);
            }
			int len = S.length();
			for(int i = 0; i < len; i++) {
				int k = (len-1) - i;
	            digit[i] = (int(S[k])-48);
			}
		}
		
		int at(int index);
		void set(ll S);
        int sign();
        void set_sign(int sign);
        static bool compare(BigNumber* a, BigNumber* b); // a < b
		static BigNumber add(BigNumber* a, BigNumber* b); // a + b
		static BigNumber subtract(BigNumber* a, BigNumber* b); // a - b
		static BigNumber multiply(BigNumber* a, BigNumber* b); // a * b
		void print();
};

int BigNumber::at(int index) {
	if (0 <= index && index < MAX_LEN)
		return digit[index];
	return 0;
}

void BigNumber::set(ll S) {
    if (S < 0) {
        set_sign(-1);
        S *= -1;
    }
    int i = 0;
	while (i < MAX_LEN) {
		digit[i++] = S % 10;
		S /= 10;
	}
}

int BigNumber::sign() {
    return digit[MAX_LEN];
}

void BigNumber::set_sign(int sign) {
    if (sign >= 0)
        digit[MAX_LEN] = 0;
    else
        digit[MAX_LEN] = -1;
}

bool BigNumber::compare(BigNumber* a, BigNumber* b) {
    // is a smaller than b
    for (int i = a->MAX_LEN; i >= 0; --i) {
        if (a->at(i) == b->at(i)) {
            continue;
        }
        return a->at(i) < b->at(i);
    }
    return false;
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

BigNumber BigNumber::subtract(BigNumber* a, BigNumber* b) { // a - b
	BigNumber res;
    if (BigNumber::compare(a, b)) { // if a smaller than b
        res.set_sign(-1);
        swap(a, b);
    }

	int carry = 0;
    for(int i = 0; i < res.MAX_LEN; i++) {
        res.digit[i] = a->at(i) - b->at(i) - carry;

        if (res.digit[i] < 0) {
            res.digit[i] += 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    
    return res;
}

BigNumber BigNumber::multiply(BigNumber* a, BigNumber* b) {
	BigNumber res;
    res.set_sign(-(int)((a->sign() < 0) ^ (b->sign() < 0)));

    for(int i = 0; i < a->MAX_LEN; i++) {
        int carry = 0;
        for(int j = 0; i+j < b->MAX_LEN; j++) {
            res.digit[i+j] += a->at(i) * b->at(j) + carry;
            carry = res.digit[i+j] / 10;
            res.digit[i+j] %= 10;
        }
    }
    
    return res;
}

void BigNumber::print() {
	bool flag = true;
    if (digit[MAX_LEN] == -1)
        cout << '-';
    for(int i = MAX_LEN-1; i >= 0; i--) {
        flag = flag && (digit[i] == 0);
        if (!flag || i == 0) {
            cout << digit[i];
        }
    }
}

int main(void) {
	string A, B;
	cin >> A >> B;
	
	BigNumber a(A);
	BigNumber b(B);
	
	BigNumber res1 = BigNumber::add(&a, &b);
	res1.print();
	
    cout << '\n';

    BigNumber res2 = BigNumber::subtract(&a, &b);
	res2.print();
    
    cout << '\n';

    BigNumber res3 = BigNumber::multiply(&a, &b);
	res3.print();
}
