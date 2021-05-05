#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map<string, int> m;
	set<int> len;

	for (int i = 0; i < phone_book.size(); i++) {
		len.insert(phone_book[i].length()); // ���� �� �ִ� ���λ��� ���̸� Ȯ��.
	}

	for (int i = 0; i < phone_book.size(); i++) {
		for (auto iter = len.begin(); iter != len.end(); iter++) {
			if (phone_book[i].length() > *iter) { // ���λ� ���� ���� ū ���ڿ��� �� ���ڵ��� ����.
				string str = phone_book[i].substr(0, *iter);
				m[str] = 0;
			}
		}
	}

	for (int i = 0; i < phone_book.size(); i++) {
		if (m.find(phone_book[i]) != m.end()) // ��Ͽ� �ִ� ��ȣ�� ���λ簡 �Ǵ°� �����ϴ��� Ȯ��.
			return false;
	}

	return answer;
}