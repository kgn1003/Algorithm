#include <iostream>
using namespace std;
int change[6] = { 500, 100, 50, 10, 5, 1 }, answer, N;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int res = 1000 - N;
	
	for (int i = 0; i < 6; i++) {
		if (res / change[i] > 0) {
			answer += res / change[i];
			res %= change[i];
		}
	}
	cout << answer;
}