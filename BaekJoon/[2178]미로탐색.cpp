#include <iostream>
#include <queue>
using namespace std;

int N, M, arr[101][101], map[101][101];
char c;
int dy[] = { -1,1,0,0 }; int dx[] = { 0,0,1,-1 };
int BFS(pair<int,int> pos) {
	queue<pair<int, int>> q;
	q.push(pos);
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny == N && nx == M)
					return map[y][x] + 1;
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && arr[ny][nx] && !map[ny][nx]) {
					map[ny][nx] = map[y][x] + 1;
					q.push({ ny,nx });
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
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	cout << BFS({ 1, 1 }) + 1;
	return 0;
}