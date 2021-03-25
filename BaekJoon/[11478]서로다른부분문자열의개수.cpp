#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	set <string> ans;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 1; j <= s.length(); j++) {
			if (i + j > s.length()) 
				break;
			string cmp = s.substr(i, j);
			cout << "cmp " <<cmp << endl;
			ans.insert(cmp);
		}
	}
	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << *i << endl;
	}
	
	cout << ans.size();
	return 0;
}