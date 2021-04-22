#include <iostream>
#include <vector>
using namespace std;
int N, dy[] = {0,1,0,-1}, dx[] = {-1,0,1,0}, answer;
vector<pair<pair<int, int>,int>> pos[4] = {
	{ {{-1,-1},10},{{-1,0},7},{{-1,1},1},{{-2,0},2},{{0,-2},5},{{1,-1},10},{{1,0},7},{{1,1},1},{{2,0},2}}, // ÁÂ
{{{-1,-1},1},{{0,-1},7},{{0,-2},2},{{1,-1},10},{{2,0},5},{{1,1},10},{{0,1},7},{{0,2},2},{{-1,1},1}}, // ÇÏ
{{{-1,-1},1},{{-1,0},7},{{-1,1},10},{{-2,0},2},{{0,2},5},{{1,-1},1},{{1,0},7},{{1,1},10},{{2,0},2}}, // ¿ì
{{{-1,-1},10},{{0,-1},7},{{1,-1},1},{{0,-2},2},{{-2,0},5},{{1,1},1},{{0,1},7},{{0,2},2},{{-1,1},10}} // »ó
};
int A[501][501], map[501][501];

int solution(int sy, int sx, int dist) {
	while (true) {
		int idx = 2;
		if (dist % 2) {
			idx = 0;
		}
		for (int cnt = 0; cnt < 2; cnt++) {

			for (int i = 0; i < dist; i++) {

				int y = sy, x = sx;
				sy = y + dy[idx]; sx = x + dx[idx];
				int ans = A[sy][sx];
				int temp = 0; 
				for (int j = 0; j < pos[idx].size(); j++) {

					int ny = sy + pos[idx][j].first.first, nx = sx + pos[idx][j].first.second;
					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {

						A[ny][nx] += (A[sy][sx]) * (pos[idx][j].second)/100;
						temp += (A[sy][sx] * pos[idx][j].second)/100;
					
					}
					else {
						temp += (A[sy][sx] * pos[idx][j].second) / 100;

						answer += (A[sy][sx] * pos[idx][j].second)/100;
					}

				}

				A[sy][sx] = 0;

				int ny = sy + dy[idx], nx = sx + dx[idx];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {
					A[ny][nx] += ans - temp;
				}
				else {
					answer += ans - temp;
				}
				if (sy == 1 && sx == 1)
					return answer;
				map[sy][sx] = dist;
				
			}
			idx++;
		}
		dist++;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int sy = (N / 2) + 1, sx = (N/2)+1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	cout << solution(sy, sx, 1);
	return 0;
}
