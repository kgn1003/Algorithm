#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int N, M, map[101][101], check[101][101], cheese, answer;
bool visited[101][101];

void solution(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	int idx = 0;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			visited[y][x] = true;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
					if (!visited[ny][nx] && !map[ny][nx]) {
						visited[ny][nx] = true;
						q.push({ ny,nx });
					}
					else if (map[ny][nx]) {
						check[ny][nx]++;
						if (check[ny][nx] > 1) {
							map[ny][nx] = 0;
							visited[ny][nx] = true;
							cheese--;
						}
					
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				cheese++;
		}
	}
	while (cheese > 0) {
		solution({ 1,1 });
		answer++;
		memset(visited, false, sizeof(visited));
		memset(check, 0, sizeof(check));
	}

	cout << answer;

	return 0;
}