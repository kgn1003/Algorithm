#include <iostream>
#include <string>
using namespace std;
int N, K;

string solution(string s, int ans_len) {
	string answer = "";
	int len = 0;
	answer += s[0];

	for (int i = 1; i < s.length(); i++) {
		if (answer[len] >= s[i]) {
			if (ans_len == len + 1)
				continue;
			answer += s[i];
			len++;
		}
		else {
			int temp = len;
			for (int j = temp; j >= 0; j--) {
				if (answer[j] < s[i]) {
					answer.erase(j);
					K--;
					len--;
					if (K == 0) {
						for (; i < s.length(); i++) {
							answer += s[i];
						}
						return answer;
					}

				}
				else
					break;
			}
			answer += s[i];
			len++;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s= "";
	cin >> N >> K >> s;
	cout << solution(s,N-K);
}