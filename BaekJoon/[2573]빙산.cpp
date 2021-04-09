#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };
int N,M,map[301][301], answer, init_cnt;
bool visited[301][301], checked[301][301];
queue<pair<int, int>>q;
stack<pair<int, int>>s;

int check_island() {

	if (q.size() == 0) {
		answer = 0;
		return 0;
	}

	int sy = q.front().first, sx = q.front().second;
	s.push({ sy,sx });

	int cnt = 1;
	memset(checked, false, sizeof(checked));
	while (!s.empty())
	{
			int y = s.top().first , x = s.top().second;
			checked[y][x] = true;
			s.pop();
			//cout << "y : " << y << " x : " << x << endl;
			for (int j = 0; j < 4; j++) {
				int ny = y + dy[j], nx = x + dx[j];
				if (!checked[ny][nx] && map[ny][nx]) {
					cnt++;
					checked[ny][nx] = true;
					s.push({ ny,nx });
				}
			}
		
	}
	if (cnt == init_cnt)
		return 1;
	else
		return 0;
}

void solution() {
	answer++;
	memset(visited, false, sizeof(visited));
	int q_size = q.size();
	for (int i = 0; i < q_size; i++) {
		int y = q.front().first, x = q.front().second;
		bool flag = true;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j], nx = x + dx[j];
			if (!visited[ny][nx] && map[ny][nx] == 0) {
				map[y][x]--;
				if (map[y][x] == 0) {
					init_cnt--;
					visited[y][x] = true;
					flag = false;
					break;
				}
			}
		}
		if (flag)
			q.push({ y,x });
	}
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= M; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				q.push({ i,j });
				init_cnt++;
			}
		}
	}

	while (1) {
		if (check_island() == 0) {
			break;
		}
		else {
			solution();
		}
	}

/*
	while (check_island()) {
		cout << 1 << endl;
		solution();
	}*/
	cout << answer;
	return 0;
}