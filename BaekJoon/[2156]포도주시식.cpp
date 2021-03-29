#include <iostream>
using namespace std;
int N, wine[10001], sip[10001], answer;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> wine[i];
	}
	sip[1] = wine[1]; sip[2] = wine[1] + wine[2];

	for (int i = 3; i <= N; i++) {
		int a = sip[i - 3] + wine[i - 1] + wine[i], b = sip[i - 2] + wine[i], c = sip[i-1];
		int d = a > b ? a : b;
		sip[i] = c > d ? c : d;
	}
	
	for (int i = 1; i <= N; i++) {
		answer = answer > sip[i] ? answer : sip[i];
	}
	cout << answer;
}