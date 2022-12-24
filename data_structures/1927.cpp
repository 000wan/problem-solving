#include <iostream>
#include <cstdlib>
using namespace std;

// #1927 MinHeap
class MinHeap {
	public:
		MinHeap() {}
		void insert(int x);
		int pop();
	private:
		void swap(int i, int j);
		void upheap(int i);
		void downheap(int i);
		int length{ 0 };
		int data[100001];
};

void MinHeap::swap(int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void MinHeap::upheap(int i) {
	int ind = i;
	while (ind > 1) {
		int pred = ind / 2;
		
		if (data[ind] < data[pred]) {
			swap(ind, pred);
			ind = pred;
		} else {
			break;
		}
	}
}

void MinHeap::downheap(int i) {
	int ind = i;
	while (ind * 2 <= length) {
		int next = ind * 2;
		if (next+1 <= length && data[next] > data[next+1])
			next += 1;
		
		if (data[ind] < data[next])
			break;
		swap(ind, next);
		ind = next;
	}
}

void MinHeap::insert(int x) {
	data[++length] = x;
	upheap(length);
}

int MinHeap::pop() {
	if (length == 0)
		return 0;
	int minima = data[1];
	
	swap(1, length);
	data[length--] = 0;
	downheap(1);
	return minima;
}
// ----------------------------------------------------------

// #11279 MaxHeap
class MaxHeap {
	public:
		MaxHeap() {}
		void insert(int x);
		int pop();
	private:
		void swap(int i, int j);
		void upheap(int i);
		void downheap(int i);
		int length{ 0 };
		int data[100001];
};

void MaxHeap::swap(int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void MaxHeap::upheap(int i) {
	int ind = i;
	while (ind > 1) {
		int pred = ind / 2;
		
		if (data[ind] > data[pred]) {
			swap(ind, pred);
			ind = pred;
		} else {
			break;
		}
	}
}

void MaxHeap::downheap(int i) {
	int ind = i;
	while (ind * 2 <= length) {
		int next = ind * 2;
		if (next+1 <= length && data[next] < data[next+1])
			next += 1;
		
		if (data[ind] > data[next])
			break;
		swap(ind, next);
		ind = next;
	}
}

void MaxHeap::insert(int x) {
	data[++length] = x;
	upheap(length);
}

int MaxHeap::pop() {
	if (length == 0)
		return 0;
	int minima = data[1];
	
	swap(1, length);
	data[length--] = 0;
	downheap(1);
	return minima;
}
// ----------------------------------------------------------

// #11286 AbsMinHeap
class AbsMinHeap {
	public:
		AbsMinHeap() {}
		void insert(int x);
		int pop();
	private:
		bool compare(int i, int j);
		void swap(int i, int j);
		void upheap(int i);
		void downheap(int i);
		int length{ 0 };
		int data[100001];
};

bool AbsMinHeap::compare(int i, int j) {
	if (abs(data[i]) < abs(data[j]))
		return true;
	if (abs(data[i]) > abs(data[j]))
		return false;
	
	return (data[i] < data[j]);
}

void AbsMinHeap::swap(int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void AbsMinHeap::upheap(int i) {
	int ind = i;
	while (ind > 1) {
		int pred = ind / 2;
		
		if (compare(ind, pred)) {
			swap(ind, pred);
			ind = pred;
		} else {
			break;
		}
	}
}

void AbsMinHeap::downheap(int i) {
	int ind = i;
	while (ind * 2 <= length) {
		int next = ind * 2;
		if (next+1 <= length && compare(next+1, next))
			next += 1;
		
		if (compare(ind, next))
			break;
		swap(ind, next);
		ind = next;
	}
}

void AbsMinHeap::insert(int x) {
	data[++length] = x;
	upheap(length);
}

int AbsMinHeap::pop() {
	if (length == 0)
		return 0;
	int minima = data[1];
	
	swap(1, length);
	data[length--] = 0;
	downheap(1);
	return minima;
}
// ----------------------------------------------------------

int main(void) {
	int N;
	cin >> N;
	
	AbsMinHeap pq;
	int res[100000];
	int len = 0;
	
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		if (x == 0)
			res[len++] = pq.pop();
		else
			pq.insert(x);
	}
	for (int i = 0; i < len; i++) {
		cout << res[i] << '\n';
	}
}
