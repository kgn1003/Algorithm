#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int arr[101][101], N, M, answer, cheese;
bool visited[101][101];
int dy[] = { 1,-1,0,0 }; int dx[] = { 0,0,1,-1 };
queue <pair<int, int>> q;

int BFS(pair<int, int> p) {
	q.push(p);
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && !visited[ny][nx]) {
					if (arr[ny][nx] == 0) {
						q.push({ ny,nx });
						visited[ny][nx] = true;
					}
					else {
						cheese--;
						arr[ny][nx] = 0;
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	return cheese;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cheese++;
		}
	}
	int time = 0;
	while (cheese > 0) {
		answer = cheese;
		time++;
		BFS({ 1,1 });
		memset(visited, false, sizeof(visited));
	}
	cout << time << "\n";
	cout << answer;
}
