#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
using namespace std;
int N, time[MAX], ans[MAX], load[MAX], answer;
vector<int> v[MAX];

int solution() {
	queue <int> q;
	for (int i = 1; i <= N; i++) {
		if (load[i] == 0) {
			q.push(i);
			ans[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			ans[next] = ans[next] > ans[cur] + time[next] ? ans[next] : ans[cur] + time[next];
			load[next]--;
			if (load[next] == 0) q.push(next);
		}
	}
	for (int i = 0; i < N; i++) {
		answer = answer > ans[i] ? answer : ans[i];
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int p_work, order;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> p_work;
		for (int j = 0; j < p_work; j++) {
			cin >> order;
			v[i].push_back(order);
			load[order]++;
		}
	}

	cout << solution();

	return 0;
}