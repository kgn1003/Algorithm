#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M, A, B, C, answer, high;
vector<pair<int, int>> v[10001];
bool visited[10001];
vector <int> weight;
bool checked[100000001];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	return a.second > b.second;
}

bool bfs(int start, int end, int w) {
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < v[cur].size(); j++) {
				int nxt = v[cur][j].first, nxt_w = v[cur][j].second;
				if (!visited[nxt] && w <= nxt_w) {
					if (nxt == end)
						return true;
					visited[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}
	return false;
}

int solution(int f1, int f2) {
	int low = 0;
	while (low <= high) {
		memset(visited, false, sizeof(visited));
		int mid = (high+low) / 2;
		queue<int> q;
		q.push(f1);
		bool flag = bfs(f1, f2, mid);

		if (flag) {
			answer = answer > mid ? answer : mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
		v[B].push_back({ A,C });
		high = high > C ? high : C;
	}
	cin >> A >> B;
	
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
	}

	cout << solution(A, B);

	return 0;
}