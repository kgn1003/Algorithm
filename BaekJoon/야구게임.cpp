#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int hit[51][10], base[5], lineup[10], N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int cal_score() {
	int score = 0, pos = 1;

	for (int i = 1; i <= N; i++) {
		int out = 0;
		while (out < 3) {
			if (hit[i][lineup[pos]] == 0)
				out++;
			else if (hit[i][lineup[pos]] == 1) {
				if (base[3] == 1) {
					score++;
					base[3] = 0;
				}
				if (base[2] == 1) {
					base[3] = 1;
					base[2] = 0;
				}
				if (base[1] == 1) {
					base[2] = 1;
					base[1] = 0;
				}
				base[1] = 1;
			}
			else if (hit[i][lineup[pos]] == 2) {
				if (base[3] == 1) {
					score++;
					base[3] = 0;
				}
				if (base[2] == 1) {
					score++;
				}
				if (base[1] == 1) {
					base[3] = 1;
					base[1] = 0;
				}
				base[2] = 1;
			}
			else if (hit[i][lineup[pos]] == 3) {
				if (base[3] == 1) {
					score++;
				}
				if (base[2] == 1) {
					score++;
					base[2] = 0;
				}
				if (base[1] == 1) {
					score++;
					base[1] = 0;
				}
				base[3] = 1;
			}
			else {
				for (int i = 1; i < 4; i++) {
					if (base[i] == 1) {
						base[i] = 0;
						score++;
					}
				}
				score++;
			}
			pos++;
			if (pos > 9)
				pos = 1;
		}
		memset(base, 0, sizeof(base));
	}

	return score;
}

int main() {
	int answer = 0, score = 0;
	vector <int> entry = { 2,3,4,5,6,7,8,9 };
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> hit[i][j];
		}
	}

	do {
		memset(lineup, 0, sizeof(lineup));
		int idx = 0, num = 1;
		while (num < 10)
		{
			if (num == 4) {
				lineup[num++] = 1;
				continue;
			}
			lineup[num++] = entry[idx++];
		}
		score = cal_score();

		if (answer < score) {
			answer = score;
		}

	} while (next_permutation(entry.begin(), entry.end()));
	cout << answer;
	return 0;
}
