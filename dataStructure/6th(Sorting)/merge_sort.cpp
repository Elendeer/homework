#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int q[N];
int temp[N];

void merge_sort(int l, int r, int q[]) {
	if (l >= r) return ;

	int mid = (l + r) >> 1;
	merge_sort(l, mid, q);
	merge_sort(mid + 1, r, q);

	int i = l, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= r) {
		if (q[i] < q[j]) temp[k ++ ] = q[i ++ ];
		else temp[k ++ ] = q[j ++ ];
	}

	while (i <= mid) temp[k ++ ] = q[i ++ ];
	while (j <= r) temp[k ++ ] = q[j ++ ];

	for (int i = l, j = 0; j < k; ++ i, ++ j) {
		q[i] = temp[j];
	}
}

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++ i ) {
		scanf("%d", &q[i]);
	}

	merge_sort(0, n - 1, q);

	for (int i = 0; i < n; ++ i ) {
		printf("%d ", q[i]);
	}

	return 0;
}
