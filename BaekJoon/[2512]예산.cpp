#include <iostream>
#include <algorithm>

using namespace std;
int N, asset[10001];
long long M, answer;

int binary_search() {
	int low = 1, high = asset[N - 1];
	while (low <= high) {
		int mid = (low + high) / 2;
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			if (asset[i] < mid) {
				ans += asset[i];
			}
			else {
				ans += mid;
			}
		}
		if (M >= ans) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> asset[i];
	}
	sort(asset, asset + N);
	
	cin >> M;
	cout << binary_search();
	return 0;
}