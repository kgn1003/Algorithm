#include <iostream>
#include <algorithm>

using namespace std;

bool selected[9], flag = false;
int dwarfs[9], answer[7], target = 100;

void DFS(int idx, int cnt) {
	if (flag)
		return;
	
	if (cnt == 7) {
		int ans = 0, j = 0;
		for (int i = 0; i < 9; i++) {
			if (selected[i] == true) {
				answer[j++] = dwarfs[i];
				ans += dwarfs[i];
			}
		}
		if (ans == target)
			flag = true;

		return;
	}

	for (int i = idx; i < 9; i++) {
		if (selected[i] == true) continue;
		selected[i] = true;
		DFS(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> dwarfs[i];
	}
	sort(dwarfs, dwarfs+9);
	DFS(0, 0);

	for (int i = 0; i < 7; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}