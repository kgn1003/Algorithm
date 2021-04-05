#include <iostream>
#include <string>
using namespace std;
int N, M, K, answer;
string s[50];
char c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	cin >> K;

	for (int i = 0; i < N; i++) {
		int zeroCnt = 0;
		for (int y = 0; y < M; y++) {
			if (s[i][y] == '0')
				zeroCnt++;
		}
		int sum = 0;
		if (zeroCnt <= K && zeroCnt % 2 == K % 2) {
			for (int y = 0; y < N; y++) {
				if (s[i] == s[y]) {
					sum++;
				}
			}
		}
		answer = answer > sum ? answer : sum;
	}

	cout << answer;
}