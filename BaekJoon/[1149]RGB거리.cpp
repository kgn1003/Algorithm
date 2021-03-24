#include <iostream>
using namespace std;

int N, RGB[1001][4], answer[1001][4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> RGB[i][j];
		}
	}
	answer[1][1] = RGB[1][1]; answer[1][2] = RGB[1][2]; answer[1][3] = RGB[1][3];

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) {
				answer[i][j] = answer[i - 1][2] < answer[i - 1][3] ? answer[i - 1][2] : answer[i - 1][3];
			}
			else if (j == 2) {
				answer[i][j] = answer[i - 1][1] < answer[i - 1][3] ? answer[i - 1][1] : answer[i - 1][3];
			}
			else {
				answer[i][j] = answer[i - 1][1] < answer[i - 1][2] ? answer[i - 1][1] : answer[i - 1][2];
			}
			answer[i][j] += RGB[i][j];
		}
	}
	int ans = answer[N][1];
	for (int i = 2; i <= 3; i++) {
		ans = ans < answer[N][i] ? ans : answer[N][i];
	}
	cout << ans;

	return 0;
}