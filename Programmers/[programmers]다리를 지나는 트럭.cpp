#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1, w = 0, next = 0, check = 0;
	deque <pair<int, int>> dq;
	for (int i = 0; i < truck_weights.size(); i++) {
		dq.push_back({ i,0 });
	}

	while (!dq.empty()) {
		answer++;
		if (next < truck_weights.size() && w + truck_weights[next] <= weight) { // 다음 차례의 트럭이 올라올 수 있는 무게라면 다리에 올라옴.
			w += truck_weights[next++];
			check++; // 올라온 트럭 갯수 확인.
		}

		bool flag = false;

		for (int i = 0; i < check; i++) {
			dq[i].second += 1;
			if (dq[i].second == bridge_length) // 트럭이 다 지났으면 확인
				flag = true;
		}
		if (flag) { 
			w -= truck_weights[dq.front().first];
			dq.pop_front();
			check--;
		}
	}
	return answer;
}