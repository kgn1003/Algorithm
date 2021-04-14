#include <iostream>
#include <queue>
using namespace std;
int N, K, L,X, y_pos, x_pos,map[101][101], answer, direction;
char C;
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };
bool visited[101][101];
queue<pair<int, char>> d;
deque<pair<int, int>> dq;
int solution(int sy, int sx) {
	int t = d.front().first;
	char nxd = d.front().second;
	d.pop();
	dq.push_front({ sy,sx });
	visited[sy][sx] = true;
	while (true) {
		answer++;
		int cy = dq.front().first, cx = dq.front().second;
		int ny = cy + dy[direction], nx = cx + dx[direction];
		if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && !visited[ny][nx]) {
			if (map[ny][nx] == 1) {
				map[ny][nx] = 0;
				dq.push_front({ ny,nx });
				visited[ny][nx] = true;
			}
			else {
				dq.push_front({ ny,nx });
				visited[ny][nx] = true;
				int ty = dq.back().first, tx = dq.back().second;
				visited[ty][tx] = false;
				dq.pop_back();
			}
		}
		else {
			return answer;
		}

		if (answer == t) {
			if (nxd == 'L') {
				direction = (direction + 3) % 4;
			}
			else {
				direction = (direction + 1) % 4;
			}
			if (!d.empty()) {
				t = d.front().first; nxd = d.front().second;
				d.pop();
			}
			else {
				t = 0;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> y_pos >> x_pos;
		map[y_pos][x_pos] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		d.push({ X,C });
	}
	
	cout << solution(1, 1);
	return 0;
}