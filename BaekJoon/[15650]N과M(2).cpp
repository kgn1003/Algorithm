#include <iostream>
using namespace std;

int N, M;
bool selected[9];

void DFS(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 1; i <= N; i++) {
			if (selected[i] == true)
				cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (selected[i] == true) continue;
		selected[i] = true;
		DFS(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	DFS(1, 0);
}