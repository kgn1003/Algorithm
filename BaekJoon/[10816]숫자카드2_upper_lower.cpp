#include <iostream>
#include <algorithm>

using namespace std;
int N, M, input[500001];

int u_bound(int num) {
	int low = 0, high = N - 1, mid, target;
	while (low <= high) {
		mid = (low + high) / 2;
		target = input[mid];
		if (target <= num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high;
}
int l_bound(int num) {
	int low = 0, high = N - 1, mid, target;
	while (low <= high) {
		mid = (low + high) / 2;
		target = input[mid];
		if (target < num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return low;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> input[i];
	sort(input, input + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		cout << u_bound(num) - l_bound(num) + 1 << " ";
	}
}