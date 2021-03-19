#if 0
#include <iostream>
#include <queue>

using namespace std;

int tomato[102][102][102];
int m, n, h;
queue <pair<int,pair<int,int>>> q;
int dy[] = { 1,-1,0,0 }; int dx[] = { 0,0,1,-1 }; int ud[] = { -1,1 };

int solution() {
	int day = 0;
	while (!q.empty())
	{
		day++;
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			pair<int, pair<int, int>> t = q.front();
			q.pop();
			for (int u = 0; u < 2; u++) {
				int nh = t.first + ud[u];
				int ny = t.second.first;
				int nx = t.second.second;
				if (nh >= 1 && nh <= h) {
					if (tomato[nh][ny][nx] == 0) {
						tomato[nh][ny][nx] = 1;
						q.push(make_pair(nh, make_pair(ny, nx)));
					}
				}
			}
			for (int j = 0; j < 4; j++) {
				int nh = t.first;
				int ny = t.second.first + dy[j];
				int nx = t.second.second + dx[j];
				if (ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
					if (tomato[nh][ny][nx] == 0) {
						tomato[nh][ny][nx] = 1;
						q.push(make_pair(nh, make_pair(ny, nx)));
					}
				}
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++) {
				if (tomato[i][y][x] == 0) {
					return -1;
				}
			}
		}
	}

	return day-1;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool flag = false;
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++) {
				cin >> tomato[i][y][x];
				if (tomato[i][y][x] == 1) {
					q.push(make_pair(i,make_pair(y,x)));
				}
			}
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int y = 1; y <= n; y++) {
			for (int x = 1; x <= m; x++) {
				if (tomato[i][y][x] == 0) {
					flag = true;
				}
			}
		}
	}

	if (flag)
		cout << solution();
	else
		cout << 0;

	return 0;
}
#endif