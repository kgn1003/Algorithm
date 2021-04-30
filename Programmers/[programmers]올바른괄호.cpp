#include<string>
#include<stack>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack <char> L;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') { // '(' �� ��� stack�� ����.
			L.push(s[i]);
		}
		else { // ')' �� ���
			if (L.empty()) { // stack�� '(' ������ false.
				answer = false;
				break;
			}
			else { // stack�� '(' ������ pop()
				L.pop();
			}
		}
	}
	if (!L.empty()) // �� �˻��ϰ� ���� stack�� ���� �ִ� ���Ұ� ������ ��ȣ�� ������ �ٸ� ���̹Ƿ� false.
		answer = false;
	return answer;
}