#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
long long answer;
int N ,cnt = 9, alphabet[26];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			alphabet[s[j] - 'A'] += pow(10, s.length() - j - 1);
		}
	}
	sort(alphabet, alphabet + 26, cmp);

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0)
			break;
		answer += alphabet[i] * cnt--;
	}
	
	cout << answer << endl;
	return 0;
}