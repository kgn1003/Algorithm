#include <iostream>
using namespace std;
int N, num, answer, ans_len[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (answer > 0) {
			if (ans_len[answer - 1] >=  num) {
				for (int j = 0; j <= answer - 1; j++) {
					if (ans_len[j] == num)
						break;
					if (ans_len[j] > num) {
						ans_len[j] = num;
						break;
					}
				}
			}
			else {
				ans_len[answer++] = num;
			}
		}
		else {
			ans_len[answer++] = num;
		}
	}
	cout << answer;
	return 0;
}