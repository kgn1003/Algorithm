#include <iostream>
using namespace std;
long long N, answer[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	answer[1] = 1; answer[2] = 2;
	for (int i = 3; i <= N; i++) {
		answer[i] = (answer[i - 1] + answer[i - 2]) % 10007;
	}
	cout << answer[N];
	return 0;
}