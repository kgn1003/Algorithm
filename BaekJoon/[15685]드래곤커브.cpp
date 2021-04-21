#include <iostream>
#include <vector>
using namespace std;
int N, y, x, d, g, answer, map[101][101];
int dy[] = { 0,-1,0,1 }, dx[] = { 1,0,-1,0 };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		for (int j = 0; j <= g; j++) {
			int v_size = v.size();
			if (j == 0) {
				int ny = y + dy[d], nx = x + dx[d];
				v.push_back(d);
				y = ny; x = nx;
				map[y][x] = 1;
				continue;
			}

			for (int k = v_size - 1; k >= 0; k--) {
				int next = (v[k] + 1) % 4;
				int ny = y + dy[next], nx = x + dx[next];
				v.push_back(next);
				y = ny; x = nx;
				map[y][x] = 1;
			}

		}
	}
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			int rect = map[i - 1][j - 1] + map[i - 1][j] + map[i][j - 1] + map[i][j];
			if (rect == 4)
				answer++;
		}
	}
	cout << answer;
	return 0;
}