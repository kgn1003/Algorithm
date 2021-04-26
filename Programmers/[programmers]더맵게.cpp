#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;
int solution(vector<int> scoville, int K) {
	int answer = 0;
	int v_size = scoville.size();
	for (int i = 0; i < v_size; i++) {
		pq.push(scoville[i]);
	}

	while (true) {
		int pq_size = pq.size();
		if (pq_size == 1) {
			if (pq.top() >= K)
				return answer;
			else
				return -1;
		}
		else {
			int num1 = pq.top(); pq.pop();
			if (num1 >= K) {
				return answer;
			}
			answer++;
			int num2 = pq.top(); pq.pop();
			int temp = num1 + (num2 * 2);
			pq.push(temp);
		}
	}
	return answer;
}