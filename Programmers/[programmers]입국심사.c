#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());   
 	long long low = 0, high = 1000000000000000000;
	while (low <= high) {
		long long cnt = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < times.size(); i++) {
			cnt += mid / times[i];
		}
		if (cnt >= n) {
            answer = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}   
    return answer;
}
