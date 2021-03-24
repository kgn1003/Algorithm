#include <iostream>

using namespace std;
int N, M, arr[9], selected[9];

void DFS(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (selected[i] == M) continue;
		selected[i]++;
		arr[cnt] = i;
		DFS(i, cnt+1);
		selected[i]--;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	DFS(1,0);
	return 0;
}