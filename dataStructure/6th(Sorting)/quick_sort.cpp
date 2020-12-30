#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int q[N];

void quick_sort(int l, int r, int q[]) {
	if (l >= r) return ;

	int i = l - 1, j = r + 1, x = q[(l + r) >> 1];

	while (i < j) {
		do ++ i; while (q[i] < x);
		do -- j; while (q[i] > x);

		if (i < j) {
			swap(q[i], q[j]);
		}
	}

	quick_sort(l, j, q);
	quick_sort(j + 1, r, q);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++ i ) {
		scanf("%d", &q[i]);
	}

	quick_sort(0, n - 1, q);

	for (int i = 0; i < n; ++ i ) {
		cout << q[i] << " ";
	}
	
	return 0;
}
