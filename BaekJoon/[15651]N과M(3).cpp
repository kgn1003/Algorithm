#include <iostream>

using namespace std;

int N, M, selected[8];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++)
			cout << selected[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		selected[cnt] = i;
		DFS(cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	DFS(0);
	return 0;
}