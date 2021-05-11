#include <iostream>
#include <queue>
#define INF 100000000
using namespace std;
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int map[101][101],broken[101][101],N,M, answer = INF;
bool visited[101][101];

int solution(int sy, int sx) {
	if (sy == M && sx == N)
		return 0;

	queue<pair<pair<int, int>, int>> q;
	q.push({ {sy,sx},0 });
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first.first, x = q.front().first.second, wall = q.front().second;
			q.pop();
			for (int next = 0; next < 4; next++) {
				int ny = y + dy[next], nx = x + dx[next];

				if (ny == M && nx == N) { // 벽을 최소로 부순 값이 나올 수 있도록 업데이트.
					answer = answer < wall ? answer : wall;
					break;
				}

				if (ny < 1 || ny > M || nx < 1 || nx > N) continue;

				if (visited[ny][nx] && broken[ny][nx] > wall) { // 방문을 했던 곳인데 벽 부순 갯수가 지금 갯수보다 큰 경우 업데이트.
					broken[ny][nx] = wall;
					if (map[ny][nx]) { 
						q.push({ {ny,nx}, wall + 1 });
					}
					else {
						q.push({ {ny,nx},wall });
					}
				}
				else if(!visited[ny][nx]){ // 방문하지 않은 곳
					visited[ny][nx] = true;
					broken[ny][nx] = wall;
					if (map[ny][nx]) {
						q.push({ {ny,nx}, wall + 1 });
					}
					else {
						q.push({ {ny,nx},wall });
					}
				}
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	char c;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	cout << solution(1, 1) ;
	
	return 0;
}