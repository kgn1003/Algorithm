#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
queue <pair<int, int>> q;
int arr[202][202];
int N, K, S, X, Y, input;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int solution(int S, int tY, int tX) {
	while (S > 0) {
		int q_size = q.size();
		for(int n = 0; n < q_size; n++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 1 || ny > N || nx < 1 || nx > N) {
					continue;
				}
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = arr[y][x];
					q.push(make_pair(ny, nx));
				}
			}
		}
		S--;
	}
	return arr[tY][tX];
}

int main() {
	vector <pair<int, int>> v[1001];
	init();
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				v[arr[i][j]].push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			q.push(make_pair(v[i][j].first, v[i][j].second));
		}
	}
	cin >> S >> X >> Y;
	cout << solution(S, X, Y) << endl;
	return 0;
}