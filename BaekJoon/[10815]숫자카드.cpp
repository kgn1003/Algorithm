#include <iostream>
#include <algorithm>
using namespace std;

int N,M,input[500001], cmp[500001];

void binary_search(int num) {
	int low = 0, high = N - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int target = input[mid];
		if (num == target) {
			//cout << target << endl;
			cout << "1 ";
			return;
		}
		if (num < target) {
			high = mid-1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << "0 ";
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> cmp[i];
	}
	sort(input, input + N);

	for (int i = 0; i < M; i++) {
		binary_search(cmp[i]);
	}

	return 0;
}