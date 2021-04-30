#include<string>
#include<stack>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack <char> L;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') { // '(' 일 경우 stack에 삽입.
			L.push(s[i]);
		}
		else { // ')' 일 경우
			if (L.empty()) { // stack에 '(' 없으면 false.
				answer = false;
				break;
			}
			else { // stack에 '(' 있으면 pop()
				L.pop();
			}
		}
	}
	if (!L.empty()) // 다 검사하고 나서 stack에 남아 있는 원소가 있으면 괄호의 갯수가 다른 것이므로 false.
		answer = false;
	return answer;
}