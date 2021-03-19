#include <iostream>

using namespace std;
int N, answer = 2000;

int main() {
	cin >> N;
	bool check = true;
	int s5 = N / 5, s3 = 0;

	for (int i = s5; i >= 0; i--) {
		for (int j = 0; j <= N / 3; j++) {
			if (5 * i + 3 * j == N) {
				check = false;
				answer = answer < i + j ? answer : i + j;
				break;
			}
			else if (5 * i + 3 * j < N) {
				continue;
			}
			else
				break;
		}
	}

	if (check)
		answer = -1;
	cout << answer;
	return 0;
}