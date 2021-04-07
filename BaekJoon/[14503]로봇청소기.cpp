#include <iostream>
using namespace std;
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1};
int N, M, direction, map[50][50],sr,sc,answer = 1;
bool visited[50][50],flag;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> sr >> sc >> direction;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];	
		}
	}
	while (!flag) {
		bool check = true;
		visited[sr][sc] = true;
		for (int i = 1; i <= 4; i++) {
			int idx = direction - i;
			if (idx < 0) idx = idx + 4;
			int ny = sr + dy[idx], nx = sc + dx[idx];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && !map[ny][nx]) {
				sr = ny; sc = nx;
				direction = idx;
				answer++;
				check = false;
				break;
			}
		}
		if (check) {
			int ny = sr+dy[(direction+2)%4], nx = sc+dx[(direction+2) % 4];
			if (map[ny][nx] == 1)
				flag = true;
			else {
				sr = ny; sc = nx;
			}
		}
	}
	cout << answer;
	return 0;
}