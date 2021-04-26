#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int v_size = stones.size();

	for (int i = 0; i < v_size; i++) {
		v.push_back(stones[i]);
	}
	sort(v.begin(), v.end());

	int low = 0, high = v[v_size - 1];

	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		bool flag = true;
		for (int i = 0; i < v_size; i++) {
			if (stones[i] - mid < 0) {
				cnt++;
				if (cnt == k) { // ¸ø°Ç³Ñ
					flag = false;
					break;
				}
			}
			else {
				cnt = 0;
			}
		}

		if (flag) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return high;
}