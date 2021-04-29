#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++) {
		q.push(progresses[i]);
	}

	int step = 0;
	while (!q.empty()) {
		int cnt = 0;
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}
		for (int i = step; i < progresses.size(); i++) {
			if (progresses[i] < 100) {
				break;
			}
			cnt++;
			step++;
			q.pop();
		}
		if (cnt != 0) {
			answer.push_back(cnt);
		}
	}

	return answer;
}