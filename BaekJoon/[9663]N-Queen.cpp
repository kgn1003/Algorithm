#include <iostream>
#include <cmath>

using namespace std;
int N,answer,map[16];

bool checked(int row) {
	for (int i = 1; i < row; i++) {
		if (map[row] == map[i] || abs(map[row] - map[i]) == row - i) {
			return false;
		}
	}
	return true;
}

void DFS(int row) {
	if (row == N+1) {
		answer++;
	}
	else {
		for (int i = 1; i <= N; i++) {
			map[row] = i;
			if (checked(row))
				DFS(row + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	DFS(1);
	cout << answer;
	return 0;
}