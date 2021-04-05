#include <iostream>
using namespace std;
int N, K;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> K;
	long low = 1, high = K, mid ,answer;
	while (low <= high) {
		int cnt = 0;
		mid = (low + high) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += mid / i < N ? mid / i : N;
		}
		if (cnt >= K) {
			answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << answer;
	return 0;
}