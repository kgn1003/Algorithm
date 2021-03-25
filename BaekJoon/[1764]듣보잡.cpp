#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
vector <string> v;
vector <string> answer;

bool binarysearch(string cmp) {
	int low = N, high = v.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		string res = v[mid];
		if (res.compare(cmp) == 0) {
			return true;
		}
		else if (res.compare(cmp) > 0) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N+M; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.begin()+N);
	sort(v.begin() + N, v.end());

	for (int i = 0; i < N; i++) {
		if (binarysearch(v[i])) {
			answer.push_back(v[i]);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}