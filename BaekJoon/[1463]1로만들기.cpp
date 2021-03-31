#include <iostream>
using namespace std;
int N, dp[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (i % 3 == 0 && i % 2 == 0)
			dp[i] = (dp[i / 3] < dp[i / 2] ? dp[i / 3] : dp[i / 2]) + 1;
		else if (i % 3 == 0)
			dp[i] = (dp[i / 3] < dp[i - 1] ? dp[i / 3] : dp[i - 1]) + 1;
		else if (i % 2 == 0)
			dp[i] = (dp[i / 2] < dp[i - 1] ? dp[i / 2] : dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[N];
	return 0;
}
