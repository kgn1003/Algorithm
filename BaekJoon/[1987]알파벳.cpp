#include <iostream>

using namespace std;
char arr[21][21];
int answer[21][21], R, C , ans = 1;
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
bool visited[26];

void DFS(int y, int x) {
	ans = ans > answer[y][x] ? ans : answer[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= 1 && ny <= R && nx >= 1 && nx <= C) {
			if (visited[arr[ny][nx] - 'A']) continue;
			visited[arr[ny][nx] - 'A'] = true;
			answer[ny][nx] = answer[y][x] + 1;
			DFS(ny, nx);
			visited[arr[ny][nx] - 'A'] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			cin >> arr[i][j];
	}
	answer[1][1] = 1; visited[arr[1][1]-'A'] = true;
	DFS(1, 1);
	cout << ans;
}