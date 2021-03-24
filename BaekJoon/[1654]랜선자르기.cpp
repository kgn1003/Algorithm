#include <iostream>
#include <algorithm>
using namespace std;

int LAN[10001], N , target;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> target;
	for (int i = 0; i < N; i++)
		cin >> LAN[i];
	sort(LAN, LAN + N);
	long long low = 1, high = LAN[N - 1];
	while (low <= high) {
		long long mid = (high + low) / 2;
		long long check = 0;
		for (int i = 0; i < N; i++) {
			check += LAN[i] / mid;
		}
		if (check >= target) {
			low = mid + 1;	
		}
		else {
			high = mid - 1;
		}
	}
	cout << high;
	return 0;
}