#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<long long> times;

long long solution() {
	long long answer = 0;

	long long low = 0, high = times[times.size() - 1] * M;
	while (low <= high) {
		long long cnt = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}
		if (cnt >= M) {
			answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	long long a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		times.push_back(a);
	}
	sort(times.begin(), times.end());
	cout << solution();
	return 0;
}