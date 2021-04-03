#include <iostream>
using namespace std;
int N,op[4], num[12], max_ans = -100000000, min_ans = 100000000;

void DFS(int result, int idx) {
	if (idx == N) {
		if (result < min_ans)
			min_ans = result;
		if (result > max_ans)
			max_ans = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0)
				DFS(result + num[idx], idx + 1);
			else if (i == 1)
				DFS(result - num[idx], idx + 1);
			else if (i == 2)
				DFS(result * num[idx], idx + 1);
			else
				DFS(result / num[idx], idx + 1);
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	DFS(num[0], 1);
	cout << max_ans << '\n' << min_ans;
}