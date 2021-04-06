#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T;
string s, answer;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		s = "";
		cin >> s;
		answer = s;
		if (next_permutation(s.begin(), s.end()))
			cout << s << '\n';
		else
			cout << answer << '\n';
		
	}
}