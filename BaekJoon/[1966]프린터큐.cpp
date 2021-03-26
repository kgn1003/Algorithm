#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, priorities[101], location;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		priority_queue<int> pq;
		queue<pair<int, int>> q;
		answer = 0;
		cin >> M >> location;
		for (int j = 0; j < M; j++) {
			cin >> priorities[j];
			q.push({ j,priorities[j] });
			pq.push(priorities[j]);
		}
		while (!q.empty()) {
			int pos = q.front().first;
			int priority = q.front().second;
			q.pop();
			if (pq.top() == priority) {
				pq.pop();
				answer++;
				if (pos == location) {
					cout << answer << "\n";
					break;
				}
			}
			else {
				q.push({ pos,priority });
			}
		}
	}
	return 0;
}