#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


using namespace std;

struct dot {
	int y, x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int N, M;
int arr[10][10];
int c_arr[10][10];

vector <int> comb;
vector <dot> virus;
vector <dot> area;
queue <dot> q;

int infect_area(vector <int> idx) {
	bool check[10][10];
	fill(check[0], check[10], false);
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			c_arr[i][j] = arr[i][j];
	}
	for (int i = 0; i < idx.size(); i++) {
		c_arr[area[idx[i]].y][area[idx[i]].x] = 1;
	}

	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
				if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && c_arr[ny][nx] == 0){
					if (check[ny][nx]) continue;
					check[ny][nx] = true;
					answer++;
					q.push({ ny,nx });
				}

		}
	}

	return answer;
}

int wall() {
	int answer = 1000;
	do {
		vector <int> idx;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 1)
				idx.push_back(i);
		}
		answer = min(answer, infect_area(idx));
	} while (next_permutation(comb.begin(), comb.end()));
	return answer;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
			if (arr[i][j] == 0)
				area.push_back({ i,j });
		}
	}

	for (int i = 0; i < 3; i++)
		comb.push_back(1);
	for (int i = 0; i < area.size() - 3; i++)
		comb.push_back(0);
	sort(comb.begin(), comb.end());

	cout << area.size() - wall() -3 << endl;

	return 0;
}
