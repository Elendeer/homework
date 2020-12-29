#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}



int main() {
	memset(h, -1, sizeof h );

	add(1, 2, 0);
	add(1, 3, 0);
	add(2, 8, 0);
	add(1, 4, 0);
	add(5, 4, 0);

	cout << "Static list simulation" << endl;
	for (int i = 1; i <= 5; ++ i) {
		cout << i << "\t";
		for (int j = h[i]; j != -1; j = ne[j]) {
			cout << e[j] << "\t";
		}
		cout << endl;
	}
	


	return 0;
}
