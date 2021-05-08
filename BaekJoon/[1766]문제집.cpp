#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> answer;
vector<int> info[32001];
int prereq[32001], N, M;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

void solution() {
	priority_queue<int, vector<int>,cmp> pq;
	for (int i = 1; i <= N; i++) {
		if (prereq[i] == 0) { // ���� Ǫ�� ������ ���� ����
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		answer.push_back(cur);
		for (int i = 0; i < info[cur].size(); i++) {
			int next = info[cur][i];
			prereq[next]--;
			if (prereq[next] == 0) pq.push(next); // �ش� ������ ���� ���� Ǯ�� �ִ� ������ ���� ���.
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int f, s;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> f >> s;
		info[f].push_back(s);
		prereq[s]++;
	}
	for (int i = 1; i <= N; i++) {
		sort(info[i].begin(), info[i].end()); //���� Ǯ�� ���� �������� �켱���� ����
	}
	solution();
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}