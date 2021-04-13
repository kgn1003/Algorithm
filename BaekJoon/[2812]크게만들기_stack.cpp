#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N, K;
string s;
void solution(string number) {
	stack <char> input;
	stack <char> answer;
	for (int i = 0; i < N; i++) {
		while ((!input.empty() && number[i] > input.top()) && K) {
			input.pop();
			K--;
		}
		if (K == N-i) break;
		
		input.push(number[i]);
	}
	while (!input.empty()) {
		answer.push(input.top());
		input.pop();
	}
	while (!answer.empty())
	{
		cout << answer.top();
		answer.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> s;
	solution(s);
	return 0;
}