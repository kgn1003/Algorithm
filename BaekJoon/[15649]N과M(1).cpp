#include <iostream>
using namespace std;

int N, M, answer[9];
bool selected[9];

void DFS(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (selected[i] == true) continue;
		selected[i] = true;
		answer[cnt] = i;
		DFS(cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	DFS(0);
	return 0;
}