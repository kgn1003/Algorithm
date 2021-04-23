#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int R, C, T, answer;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,1,-1 },map[51][51], res[51][51];
bool visited[51][51];
queue <pair<int, int>> q;
pair<int, int> u, d;

int solution() {
	while (T--)
	{
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			int cnt = 0;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny >= 1 && ny <= R && nx >= 1 && nx <= C && map[ny][nx] != -1) {
					cnt++;
					if (visited[ny][nx]) { // 원래 먼지가 있는 곳.
						res[ny][nx] += map[y][x] / 5;
					}
					else {
						map[ny][nx] = map[y][x] / 5;
						visited[ny][nx] = true;
					}
				}
			}
			map[y][x] -= (map[y][x] / 5) * cnt;
		}

		for (int i = 1; i <= R; i++) { // 미세먼지 확산 업데이트
			for (int j = 1; j <= C; j++) {
				map[i][j] += res[i][j];
			}
		}
		memset(visited, false, sizeof(visited));
		memset(res, 0, sizeof(res));

		// 공기청정기 순환
		for (int y = u.first - 1; y > 1; y--) {
			map[y][1] = map[y - 1][1];
		}

		for (int y = d.first + 1; y < R; y++) {
			map[y][1] = map[y + 1][1];
		}

		for (int x = 1; x < C; x++) {
			map[1][x] = map[1][x+1];
			map[R][x] = map[R][x+1];
		}

		for (int y = 1; y < u.first; y++) { // 위
			map[y][C] = map[y+1][C];
		}

		for (int y = R; y > d.first; y--) { // 아래
			map[y][C] = map[y - 1][C];
		}

		for (int x = C; x > 2; x--) { // 오른쪽
			map[u.first][x] = map[u.first][x-1];
			map[d.first][x] = map[d.first][x-1];
		}
		map[u.first][2] = 0;
		map[d.first][2] = 0;

		for (int i = 1; i <= R; i++) { // 공기청정기 업데이트
			for (int j = 1; j <= C; j++) {
				if (map[i][j] > 0) {
					visited[i][j] = true;
					q.push({ i,j });
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(map[i][j] != -1)
				answer += map[i][j];
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool flag = true;
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && flag) {
				u = { i,j };
				flag = false;
			}
			else if (map[i][j] == -1) {
				d = { i,j };
			}
			else if (map[i][j] != 0) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	cout << solution();
	return 0;
}