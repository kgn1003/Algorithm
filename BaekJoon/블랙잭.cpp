#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, target, answer;
vector <int> v;
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
	vector <int> sel;
	cin >> N >> target;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 3; i++) { // »ÌÀ» °¹¼ö
		sel.push_back(1);
	}
	for (int i = 0; i < N - 3; i++) { // ÀüÃ¼ - »ÌÀ» °¹¼ö
		sel.push_back(0);
	}

	sort(sel.begin(), sel.end());

	do {
		int ans = 0;
		for (int i = 0; i < sel.size(); i++) {
			if (sel[i] == 1) {
				ans += v[i];
			}
		}
		if (ans <= target && answer < ans)
			answer = ans;
	} while (next_permutation(sel.begin(), sel.end()));

	cout << answer;

	return 0;
}