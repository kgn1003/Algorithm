#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;
int N, S[21][21], answer = 200000 ,start[10], link[10];
bool select[21];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int diff_balance() {
	int s_team = 0, l_team = 0 , s = 0, l = 0;
	for (int i = 1; i <= N; i++) {
		if (select[i] == true)
			start[s++] = i;
		else
			link[l++] = i;
	}
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			if (j == i)
				continue;
			s_team += S[start[i]][start[j]];
			l_team += S[link[i]][link[j]];
		}
	}
	return abs(s_team - l_team);
}

void DFS(int idx, int cnt) {
	if (cnt == N / 2) {
		int ans = diff_balance();
		answer = answer < ans ? answer : ans;
		return;
	}
	for (int i = idx; i <= N; i++) {
		if (select[i] == true) continue;
		select[i] = true;
		DFS(i, cnt + 1);
		select[i] = false;
	}

}
/*
int diff_balance(vector<int> start, vector<int> link) {
	int s_team = 0, l_team = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			if (j == i)
				continue;
			s_team += S[start[i]][start[j]];
			l_team += S[link[i]][link[j]];
		}
	}
	return abs(s_team - l_team);
}
*/

int main() {
	init();
	vector <int> sel;
	vector <int> num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	DFS(1, 0);

/*	for (int i = 1; i <= N; i++) {
		num.push_back(i);
	}

	for (int i = 0; i < N / 2; i++) {
		sel.push_back(1);
		sel.push_back(0);
	}
	sort(sel.begin(), sel.end());
	

	do {
		int ans;
		vector <int> start;
		vector <int> link;
		for (int i = 0; i < sel.size(); i++) {
			if (sel[i] == 1) {
				start.push_back(num[i]);
			}
			else {
				link.push_back(num[i]);
			}
		}
		ans = diff_balance(start, link);
		answer = answer < ans ? answer : ans;
	} while (next_permutation(sel.begin(), sel.end()));
	*/

	cout << answer;

	return 0;
}