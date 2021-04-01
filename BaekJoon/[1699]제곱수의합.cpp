#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, answer[100010], visited[1001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	answer[1] = 1; visited[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!visited[(int)sqrt(i)]) {
			visited[(int)sqrt(i)] = 1;
			answer[i] = 1;
		}
		else {
			answer[i] = answer[(int)pow((int)sqrt(i), 2)] + answer[i - (int)pow((int)sqrt(i), 2)];
			for (int j = 1; j < (int)sqrt(i); j++) {
				answer[i] = min(answer[i], answer[(int)pow(j, 2)] + answer[i - (int)pow(j, 2)]);
			}
		}
	}
	cout << answer[N];
	return 0;
}