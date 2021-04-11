#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 2000000001
using namespace std;
int N, arr[100001], result = INF, low_ans, high_ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int low = 0, high = N -1;
	while (low < high) {
		int cmp = arr[low] + arr[high];
		if (result >= abs(cmp)) {
			result = abs(cmp);
			low_ans = arr[low];
			high_ans = arr[high];
		}
		if (cmp < 0)
			low++;
		else
			high--;
	}
	
	
	cout << low_ans << " " << high_ans;

	return 0;
}