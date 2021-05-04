#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> v1;
	vector<string> v2;
	vector<string> union_vec;
	vector<string> intsec_vec;

	for (int i = 0; i < str1.length() - 1; i++) {
		string s = str1.substr(i, 2);

		if (s.length() < 2)
			continue;
		else {
			bool flag = true;
			for (int j = 0; j < s.length(); j++) {
				s[j] = tolower(s[j]); // 대문자이면 소문자로 반환.
				if (!isalpha(s[j])) { // 알파벳인지 확인.
					flag = false;
					break;
				}
			}
			if (flag)
				v1.push_back(s);

		}
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		string s = str2.substr(i, 2);

		if (s.length() < 2)
			continue;
		else {
			bool flag = true;
			for (int j = 0; j < s.length(); j++) {
				s[j] = tolower(s[j]); // 대문자이면 소문자로 반환.
				if (!isalpha(s[j])) { // 알파벳인지 확인.
					flag = false;
					break;
				}
			}
			if (flag)
				v2.push_back(s);

		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(intsec_vec)); // 교집합
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(union_vec)); // 합집합


	double a = intsec_vec.size(), b = union_vec.size();

	if (a == 0 && b == 0)
		return 65536;
	else
		return (int)((a / b) * 65536);

}