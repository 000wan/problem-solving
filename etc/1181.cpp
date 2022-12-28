#include <iostream>
#include <string>
using namespace std;

int N;
string arr[20000];

bool cmp(int i, int j) {
	if (arr[i].length() < arr[j].length())
		return true;
	if (arr[i].length() > arr[j].length())
		return false;
	return arr[i] < arr[j];
}

void swap(int i, int j) {
	string temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void qs(int start, int stop) {
	if (start >= stop)
		return;
	
	int i = start - 1;
	int j = stop + 1;
	int p = start;
	while(true) {
		while (cmp(++i, p));
		while (cmp(p, --j));
		
		if (i >= j)
			break;
		swap(i, j);
	}
	
	swap(p, j);
	qs(start, j-1);
	qs(j+1, stop);
}

int main(void) {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	qs(0, N-1);
	
	string prev = "";
	for (int i = 0; i < N; i++) {
		if (arr[i] != prev) {
			cout << arr[i] << '\n';
			prev = arr[i];
		}
	}
}
