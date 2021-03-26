#include <iostream>
#include <unordered_map>

using namespace std;
long long N, M,answer[50001];
unordered_map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		m[a]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		cout << m[a] << " ";
	}

}
