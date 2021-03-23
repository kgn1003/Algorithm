#include <iostream>

using namespace std;
int N, triangle[501][501], answer[501][501], ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	answer[1][1] = triangle[1][1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			answer[i][j] = answer[i - 1][j] < answer[i - 1][j - 1] + triangle[i][j] ? answer[i - 1][j - 1] + triangle[i][j] : answer[i - 1][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		ans = ans < answer[N][i] ? answer[N][i] : ans;
	}

	cout << ans;
	return 0;
}