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
		len.insert(phone_book[i].length()); // 나올 수 있는 접두사의 길이를 확인.
	}

	for (int i = 0; i < phone_book.size(); i++) {
		for (auto iter = len.begin(); iter != len.end(); iter++) {
			if (phone_book[i].length() > *iter) { // 접두사 길이 보다 큰 문자열의 앞 문자들을 저장.
				string str = phone_book[i].substr(0, *iter);
				m[str] = 0;
			}
		}
	}

	for (int i = 0; i < phone_book.size(); i++) {
		if (m.find(phone_book[i]) != m.end()) // 목록에 있는 번호가 접두사가 되는게 존재하는지 확인.
			return false;
	}

	return answer;
}