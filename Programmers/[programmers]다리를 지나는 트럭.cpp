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
		if (next < truck_weights.size() && w + truck_weights[next] <= weight) { // ���� ������ Ʈ���� �ö�� �� �ִ� ���Զ�� �ٸ��� �ö��.
			w += truck_weights[next++];
			check++; // �ö�� Ʈ�� ���� Ȯ��.
		}

		bool flag = false;

		for (int i = 0; i < check; i++) {
			dq[i].second += 1;
			if (dq[i].second == bridge_length) // Ʈ���� �� �������� Ȯ��
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