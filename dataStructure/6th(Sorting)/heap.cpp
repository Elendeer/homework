#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;
int h[N], idx;

void down(int x) {
	int t = x;
	if (x * 2 <= idx && h[x * 2] < h[t]) {
		t = x * 2;
	}
	if (x * 2 + 1 <= idx && h[x * 2 + 1] < h[t] ) {
		t = x * 2 + 1;
	}

	if (t != x) {
		swap(h[t], h[x]);
		down(t);
	}
}

void up(int x) {
	while (x / 2 && h[x / 2] > h[x] ) {
		swap(h[x / 2], h[x]);
		x >>= 1;
	}
}

void push(int num) {
	h[++ idx] = num;
	up(idx);
}
void pop() {
	h[1] = h[idx -- ];
	down(1);
}

int main() {
	push(5);
	push(4);
	push(2);
	push(8);
	push(3);
	push(1);

	while (idx) {
		cout << h[1] << " ";
		pop();
	}
	cout << endl;

	return 0;
}
