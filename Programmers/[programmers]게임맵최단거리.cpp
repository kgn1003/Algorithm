#include<vector>
#include<queue>
using namespace std;
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int dist[101][101];
bool visited[101][101];
int solution(vector<vector<int>> maps)
{
	int answer = -1;
	int N = maps.size() - 1, M = maps[0].size() - 1;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 1;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (ny == N && nx == M) {
					return dist[y][x] + 1;
				}
				if (ny >= 0 && ny <= N && nx >= 0 && nx <= M && !visited[ny][nx] && maps[ny][nx]) {
					dist[ny][nx] = dist[y][x] + 1;
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
	return answer;
}