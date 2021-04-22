#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;
int N, A[21][21], elect[21][21], answer = INF;

void solution(int x, int y, int d1, int d2) {

	vector<int> v;
	memset(elect, 0, sizeof(elect));
	int sum = 0;

	for (int i = 0; i <= d1; i++) {
		elect[x + i][y - i] = 5;
		sum += A[x + i][y - i];
	}
	for (int i = 1; i <= d2; i++) {
		elect[x + i][y + i] = 5;
		sum += A[x + i][y + i];
	}
	for (int i = 1; i <= d2; i++) {
		elect[x + d1 + i][y - d1 + i] = 5;
		sum += A[x + d1 + i][y - d1 + i];
	}
	for (int i = 1; i < d1; i++) {
		elect[x + d2 + i][y + d2 - i] = 5;
		sum += A[x + d2 + i][y + d2 - i];
	}
	for (int i = 0; i < d1; i++) {
		for (int j = 1; ; j++) {
			if (elect[x + i + j][y - i] == 5)
				break;
			else {
				elect[x + i + j][y - i] = 5;
				sum += A[x + i + j][y - i];
			}
		}
	}
	for (int i = 0; i < d2; i++) {
		for (int j = 1; ; j++) {
			if (elect[x + i + j][y + i] == 5)
				break;
			else {
				elect[x + i + j][y + i] = 5;
				sum += A[x + i + j][y + i];
			}
		}
	}
	v.push_back(sum);
	sum = 0;

	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			if (!elect[r][c]) {
				elect[r][c] = 1;
				sum += A[r][c];
			}

		}
	}
	if (sum == 0)
		return;
	v.push_back(sum);
	sum = 0;
	for (int r = 1; r <= x + d2; r++) {
		for (int c = y + 1; c <= N; c++) {
			if (!elect[r][c]) {
				elect[r][c] = 2;
				sum += A[r][c];
			}
		}
	}
	if (sum == 0)
		return;
	v.push_back(sum);
	sum = 0;
	for (int r = x + d1; r <= N; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			if (!elect[r][c]) {
				elect[r][c] = 3;
				sum += A[r][c];
			}
		}
	}
	if (sum == 0)
		return;
	v.push_back(sum);
	sum = 0;
	for (int r = x + d2 + 1; r <= N; r++) {
		for (int c = y - d1 + d2; c <= N; c++) {
			if (!elect[r][c]) {
				elect[r][c] = 4;
				sum += A[r][c];
			}
		}
	}
	if (sum == 0)
		return;
	v.push_back(sum);
	sort(v.begin(), v.end());

	int temp = v[4] - v[0];

	answer = answer < temp ? answer : temp;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 <= N && y + d2 <= N) {
						solution(x, y, d1, d2);
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}