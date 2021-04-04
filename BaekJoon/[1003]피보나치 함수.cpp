#include <iostream>
using namespace std;
int T, N,answer[41][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	answer[0][0] = 1; answer[0][1] = 0;
	answer[1][0] = 0; answer[1][1] = 1;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 2; i <= N; i++) {
			answer[i][0] = answer[i - 2][0] + answer[i - 1][0];
			answer[i][1] = answer[i - 2][1] + answer[i - 1][1];
		}
		cout << answer[N][0] << " " << answer[N][1] << '\n';
	}
	return 0;
}