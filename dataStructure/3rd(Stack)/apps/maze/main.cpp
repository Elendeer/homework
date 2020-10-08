#include <iostream>
#include <vector>
#include "../../../template/Stack.hpp"

using namespace std;

int mx[4] = {0, 0, -1, 1}, my[4] = {1, -1, 0, 0};
int total = 0;

void dfs(vector<vector<int>> & maze,
		const pair<int, int> & exit,
		Stack<pair<int, int>> & s, int x, int y) {

	if (x == exit.first && y == exit.second) {
		// Succeed.
		for (auto item : s) {
			cout << "(" << item.first << ", " << item.second << ")" << "->";
		}
		cout << "Succeed" << endl;
		
		++ total;

		return;
	}

	// Boundary testing.
	if (x < 0 || x > 9 || y < 0 || y > 9) {
		return;
	}

	// If there is no wall.

	// Try every four positions.
	for (int pos = 0; pos <= 3; ++ pos) {
		int nx = x + mx[pos], ny = y + my[pos];

		// Push next step.
		if (maze[nx][ny] == 0) {
			// Mark for used.
			maze[nx][ny] = 1;
			s.push({nx, ny});
			dfs(maze, exit, s, nx, ny);

			// Back.
			maze[nx][ny] = 0;
			s.pop();
		}

	}

	return;

}


int main() {

	vector<vector<int>> maze = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	pair<int, int> exit = {8, 8};

	Stack<pair<int, int>> s;


	// Start from (1, 1)

	maze[1][1] = 0;
	s.push({1, 1});
	dfs(maze, exit, s, 1, 1);


	cout << "have " << total << " paths." << endl;

	return 0;
}
