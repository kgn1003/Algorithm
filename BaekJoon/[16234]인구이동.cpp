#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
int N, L, R, answer, map[101][101];
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int visited[101][101];
stack <pair<int, int>> s;

void DFS(int y, int x) {
	vector <pair<int, int>> ans;
	ans.push_back({ y,x });
	s.push({ y,x });
	int sum = map[y][x];
	while (!s.empty()) {
		int y = s.top().first, x = s.top().second;
		s.pop();
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j], nx = x + dx[j];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !visited[ny][nx]) {
				if (abs(map[y][x] - map[ny][nx]) >= L && abs(map[y][x] - map[ny][nx]) <= R) {
					sum += map[ny][nx];
					visited[ny][nx] = true;
					ans.push_back({ ny,nx });
					s.push({ ny,nx });
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		int y = ans[i].first, x = ans[i].second;
		map[y][x] = sum / ans.size();
	}

	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int y = i, x = j;
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k], nx = x + dx[k];
					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !visited[y][x] && !visited[ny][nx]) {
						if (abs(map[y][x] - map[ny][nx]) >= L && abs(map[y][x] - map[ny][nx]) <= R) {
							flag = false;
							if (!visited[y][x]) {
								visited[y][x] = true;
								DFS(y, x);
							}
						}
					}
				}
			}
		}
		memset(visited, false, sizeof(visited));
		if (flag)
			break;
		answer++;
	}
	cout << answer;
}