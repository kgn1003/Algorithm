#include <iostream>
using namespace std;
int N;
long long arr[10][101];
long long answer, mod = 1000000000;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= 9; i++)
		arr[i][1] = 1;

	for (int j = 2; j <= N; j++) {
		for (int i = 0; i <= 9; i++) {
			if (arr[i][j - 1] == 0)
				continue;
			else {
				if (i == 0) {
					arr[i + 1][j] += (arr[i][j - 1] % mod);
				}
				else if (i == 9) {
					arr[i - 1][j] += (arr[i][j - 1] % mod);
				}
				else {
					arr[i + 1][j] += (arr[i][j - 1] % mod);
					arr[i - 1][j] += (arr[i][j - 1] % mod);
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		answer += (arr[i][N] % mod);
	}

	cout << answer % mod;
}