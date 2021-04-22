#include <iostream>

using namespace std;

// ===== data structures needed =====
// set values according to topic requirement

int max[][3] = {
	{7, 5, 3},
	{3, 2, 2},
	{9, 0, 2},
	{2, 2, 2},
	{4, 3, 3}
};
int allocation[][3] = {
	{0, 1, 0},
	{2, 0, 0},
	{3, 0, 2},
	{2, 1, 1},
	{0, 0, 2}
};
int need[][3] = {
	{7, 4, 3},
	{1, 2, 2},
	{6, 0, 0},
	{0, 1, 1},
	{4, 3, 1}
};
int available[] = {3, 3, 2};

int save_list[5] = {0};

// ===== =====

bool ifSave() {
	int work[3];
	for (int i = 0; i < 3; ++ i ) {
		work[i] = available[i];
	}
	bool finish[5] = {false};
	
	bool all_true = false;
	int idx = 0;
	while (!all_true) {
		bool flag = false;
		int ii;
		for (int i = 0; i < 5; ++ i ) {
			if (finish[i] == false) {
				flag = true;
				for (int j = 0; j < 3; ++ j ) {
					if (need[i][j] > work[j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ii = i;
					break;
				}
			}
		
				
			if (flag) break;
		}	
	
		if (flag) {
			for (int j = 0; j < 3; ++ j ) {
				work[j] += allocation[ii][j];
			}
			finish[ii] = true;
			save_list[idx] = ii;
		}
		else {
			return false;
		}
		
		all_true = true;
		for (int i = 0; i < 5; ++ i ) {
			if (finish[i] == false) {
				all_true = false;
				break;
			}
		}
		
		++ idx;
	}
	
	return true;
}

void bankerAlgorithm(int process_no, int request[3]) {
	for (int i = 0; i < 3; ++ i ) {
		if (request[i] > need[process_no][i]) {
			cout << "resource request not available: overflow" << endl;
			return ;
		}
	}
	
	for (int i = 0; i < 3; ++ i ) {
		if (request[i] > available[i]) {
			cout << "resource request not available: resources not enough now, must wait." << endl;
			return ;
		}
	}
	
	
	// try to allocate
	for (int i = 0; i < 3; ++ i ) {
		available[i] -= request[i];
		allocation[process_no][i] += request[i];
		need[process_no][i] -= request[i];
	}
	
	// ture if succeed.
	if (ifSave()) {
		cout << "it's save to allocate." << endl;
		cout << "save list: ";
		for (int i = 0; i < 5; ++ i ) {
			cout << save_list[i] << " ";
		}
		cout << endl;
	
		return;
	}
	
	// not succeed, retrieve.
	for (int i = 0; i < 3; ++ i ) {
		available[i] += request[i];
		allocation[process_no][i] -= request[i];
		need[process_no][i] += request[i];
	}
	cout << "not save, stop." << endl;
}



int main() {
	int p1[] = {1, 0, 2};
	bankerAlgorithm(1, p1);
	
	return 0;
}
