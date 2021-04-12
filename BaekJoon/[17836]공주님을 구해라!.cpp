#include <iostream>
#include <queue>
using namespace std;
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int N, M, T, map[101][101], answer;
bool visited[101][101][2];

int solution(pair<int,int> start) {
	queue <pair<pair<int, int>, int>>q;
	q.push({ { start.first,start.second }, 0 });
	while (T--) {
		int q_size = q.size();
		answer++;
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first.first, x = q.front().first.second;
			int sword = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny == N && nx == M) {
					return answer;
				}
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && !visited[ny][nx][sword]) {
					if (map[ny][nx] == 0) {
						visited[ny][nx][sword] = true;
						map[ny][nx] = map[y][x] + 1;
						q.push({ { ny,nx }, sword });
					}
					else if (map[ny][nx] == 2) {
						visited[ny][nx][sword] = true;
						map[ny][nx] = map[y][x] + 1;
						q.push({ {ny,nx},1 });
					}
					else {
						if (sword == 1) {
							visited[ny][nx][sword] = true;
							map[ny][nx] = map[y][x] + 1;
							q.push({ {ny,nx},sword });
						}
					}
				}
			}
			/*for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					cout << map[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;*/
		}
	}
	answer = 0;
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	if (solution({ 1,1 }))
		cout << answer;
	else
		cout << "Fail";

	return 0;
}