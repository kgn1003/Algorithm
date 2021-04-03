#include <iostream>
using namespace std;

int arr[1000001], N, answer;
int binary_search(int low, int high, int target) {
	while (low <= high) {
		int mid = (low + high) / 2;
		int cmp = arr[mid];
		if (target == cmp) {
			return mid;
		}
		else if (target > cmp) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return high+1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (answer == 0) {
			arr[answer++] = a;
		}
		else {
			if (arr[answer - 1] >= a) {
				arr[binary_search(0, answer - 1, a)] = a;
			}
			else {
				arr[answer++] = a;
			}
		}
	}
	cout << answer;
	return 0;
}