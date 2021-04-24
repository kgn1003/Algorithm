#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, map[21][21], visited[21][21], direction[401], answer;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

queue <pair<pair<int, int>, int>> q;
vector<int> shark_priority[401][4];
vector<pair<pair<int, int>, int>> v;

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
	return a.second < b.second;
}

int solution() {
	int dead_line = 1000;

	while (!q.empty())
	{
		int q_size = q.size();

		if (dead_line < 0) { // 시간 초과
			return -1;
		}
		if (q_size == 1) { // 종료 조건
			return answer;
		}
		answer++;
		for (int i = 0; i < q_size; i++) {
			bool checked = false;
			int y = q.front().first.first, x = q.front().first.second, shark = q.front().second;
			int cur_d = direction[shark] - 1;
			q.pop();
			for (int j = 0; j < 4; j++) {
				// 상어 이동
				int nxt_d = shark_priority[shark][cur_d][j] - 1;
				int ny = y + dy[nxt_d], nx = x + dx[nxt_d];

				if (ny < 1 || ny > N || nx < 1 || nx > N)
					continue;
				else if (map[ny][nx] == K + 1) {
					checked = true;
					break;
				}
				else if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && map[ny][nx] == 0) {
					checked = true;
					q.push({ {ny,nx}, shark });
					direction[shark] = nxt_d + 1;
					visited[ny][nx] = shark;
					map[ny][nx] = K + 1;
					break;
				}
			}

			if (!checked) { // 자기 자신의 방향으로 가야하는 경우
				for (int i = 0; i < 4; i++) {
					int nxt_d = shark_priority[shark][cur_d][i] - 1;
					int ny = y + dy[nxt_d], nx = x + dx[nxt_d];

					if (visited[ny][nx] == shark) {
						q.push({ {ny,nx}, shark });
						direction[shark] = nxt_d + 1;
						visited[ny][nx] = shark;
						map[ny][nx] += K + 1;
						break;
					}

				}
			}
		}

		dead_line--;
		// 맵 갱신
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] > 0) {
					if (map[i][j] > K + 1)
						map[i][j] = K + 1;
					map[i][j]--;
					if (map[i][j] == 0)
						visited[i][j] = 0;
				}
			}
		}

	}
}




int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				v.push_back({ { i,j }, map[i][j] });
				visited[i][j] = map[i][j];
				map[i][j] = K;
			}
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i <= M; i++) {
		q.push(v[i-1]);
		cin >> direction[i];
	}
	int d;
	for (int shark = 1; shark <= M; shark++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> d;
				shark_priority[shark][i].push_back(d);
			}
		}
	}

	cout << solution();
	return 0;
}