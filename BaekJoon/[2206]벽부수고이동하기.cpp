#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, pair<int,bool>>> q;
int N, M;
int arr[1001][1001], ans[1001][1001], answer = -1;
bool visited[1001][1001][2];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int solution(pair<int,pair<int,int>> pos) {
	q.push(pos);
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second.first, wall = q.front().second.second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny == N && nx == M) {
					answer = ans[y][x] + 1;
					return answer;
				}
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && !visited[ny][nx][wall]) {
					if (arr[ny][nx] == 0) {
						visited[ny][nx][wall] = true;
						ans[ny][nx] = ans[y][x] + 1;
						q.push({ ny,{nx,wall} });
					}
					else {
						if (wall == 0) {
							ans[ny][nx] = ans[y][x] + 1;
							q.push({ ny,{nx,1} });
							visited[ny][nx][1] = true;
						}
					} 					
				}
			}
		}
	}
	return answer;

}

int main() {

	init();
	char input;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input;
			arr[i][j] = input - 48;
		}
	}
	ans[1][1] = 1;
	visited[1][1][0] = true;

	if (N == 1 && M == 1)
		cout << 1;
	else
		cout << solution({ 1,{1 ,0} })<< endl;

	return 0;
}