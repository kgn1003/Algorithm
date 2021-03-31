#include <iostream>
#include <algorithm>
using namespace std;

int N, C, X[200001], answer = 1;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}
	sort(X, X + N);
	if (C == 2)
		cout << X[N - 1] - X[0];
	else {
		int low = 0, high = X[N - 1], mid, cnt, tmp;
		while (low <= high) {
			mid = (low + high) / 2;
			cnt = 1;
			tmp = X[0];
			for (int i = 1; i <= N - 1; i++) {
				if (mid <= X[i] - tmp) {
					tmp = X[i];
					cnt++;
				}
			}
			if (C <= cnt) {
				answer = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		cout << high;
	}

}