#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void quicksort(int a[], int start, int stop) {
	if (start >= stop)
		return;
	
	int i = start - 1;
	int j = stop + 1;
	int p = start;
	while (true) {
		while (a[++i] < a[p]);
		while (a[--j] > a[p]);
		
		if(i >= j)
			break;
		swap(&a[i], &a[j]);
	}
	swap(&a[j], &a[p]);
	quicksort(a, start, j-1);
	quicksort(a, j+1, stop);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	int data[N];
	
	for (int i=0; i<N; i++) {
		cin >> data[i];
	}
	
	quicksort(data, 0, N-1);
	
	for (int i=0; i<N; i++) {
		cout << data[i] << "\n";
	}
}
