#include <iostream>
using namespace std;
long long N, answer[1516], mod = 1000000007;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	answer[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 0) {
			answer[i] = (answer[i - 1] * 2 + 1) % mod;
		}
		else {
			answer[i] = (answer[i - 1] * 2 - 1)%mod;
		}
	}
	cout << answer[N];
	return 0;
}