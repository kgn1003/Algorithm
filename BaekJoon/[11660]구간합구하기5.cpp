#include <iostream>
using namespace std;

int n, m, arr[1034][1034];
int subsum[1034][1034];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		int linesum = 0; // i행에 있는 숫자들의 누적합
		for (int j = 1; j <= n; j++) {
			linesum += arr[i][j];
			subsum[i][j] = subsum[i - 1][j] + linesum;
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		ans = subsum[x2][y2] - subsum[x2][y1 - 1] - subsum[x1 - 1][y2] + subsum[x1-1][y1-1];
		cout << ans << "\n";
	}
	return 0;
}
