#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
int N, answer, w, d, r[4];
deque <int> dq[4];

void solution(int wheel, int direction) {
	int x;
	int next = direction;
	r[wheel] = next;
	for (int i = wheel; i > 0; i--) { // ¿ÞÂÊ 
		if (dq[i].at(6) != dq[i - 1].at(2)) {
			r[i - 1] = -next;
			next *= -1;
		}
		else {
			break;
		}
	}
	next = direction;
	for (int i = wheel; i < 3; i++) { // ¿À¸¥ÂÊ
		if (dq[i].at(2) != dq[i + 1].at(6)) {
			r[i + 1] = -next;
			next *= -1;
		}
		else {
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (r[i] == 1) {
			x = dq[i].back();
			dq[i].pop_back();
			dq[i].push_front(x);
		}
		else if (r[i] == -1) {
			x = dq[i].front();
			dq[i].pop_front();
			dq[i].push_back(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		string input = "";
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			dq[i].push_back(input[j] - '0');
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		memset(r, 0, sizeof(r));
		cin >> w >> d;
		solution(w-1, d);
	}
	for (int i = 0; i < 4; i++) {
		if (dq[i].at(0) == 1) {
			answer += pow(2, i);
		}
	}
	cout << answer;
	return 0;
}