#include <iostream>
using namespace std;
int answer[1000001], N, M, mod = 1000000009;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	answer[1] = 1; answer[2] = 2; answer[3] = 4;
	for (int j = 0; j < N; j++) {
		cin >> M;
		for (int i = 4; i <= M; i++) {
			if (answer[i] != 0) continue;
			answer[i] = (answer[i - 3] + answer[i - 2] + answer[i - 1]) % mod;
		}
		cout << answer[M] % mod << '\n';
	}
	return 0;
}