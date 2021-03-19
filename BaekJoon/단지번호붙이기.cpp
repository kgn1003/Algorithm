#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int N, arr[26][26],check[26][26];
char input[26][26];
int dy[] = { 1,-1,0,0 }; int dx[] = { 0,0,1,-1 };

vector <int> answer;
vector <pair<int, int>> v;


int solution(int y, int x) {
	stack <pair<int, int>> s;
	s.push(make_pair(y, x));
	pair<int, int> pos;
	int cnt = 1;

	while (!s.empty()) {
		pos = s.top();
		s.pop();
		for (int i = 0; i < 4; i++) {
			int ny = pos.first + dy[i]; int nx = pos.second + dx[i];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {
				if (check[ny][nx] == 0 && arr[ny][nx] == 1) {
					cnt++;
					check[ny][nx] = 1;
					s.push(make_pair(ny, nx));
				}
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &N);
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%c", &input[i][j]);
			if (input[i][j] == '1') {
				arr[i][j] = 1;
				v.push_back(make_pair(i, j));
			}
			else {
				arr[i][j] = 0;
			}
		}
		getchar();
	}

	for (int i = 0; i < v.size(); i++) {
		int y = v[i].first, x = v[i].second;
		if (check[y][x] == 0) {
			check[y][x] = 1;
			answer.push_back(solution(y, x));
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}