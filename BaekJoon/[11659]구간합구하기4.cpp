#include <iostream>
using namespace std;

int n, m, ans, arr[100001];
int subsum[100001]; // 1부터 i까지의 합

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		subsum[i] = subsum[i - 1] + arr[i];
	}
	for (int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		cout << subsum[right] - subsum[left - 1] << "\n";
	}
	return 0;
}