#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cmath>

using namespace std;
string err = "ERROR";
long long N, input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		vector <string> op;
		while (1) {
			string s, sub;
			cin >> s;
			if (s == "NUM") {
				cin >> sub;
				op.push_back(s + " " + sub);
			}
			else if (s == "END") {
				break;
			}
			else if (s == "QUIT") {
				return 0;
			}
			else {
				op.push_back(s);
			}
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			stack <long long> s;
			bool flag = true;
			cin >> input;
			s.push(input);

			for (int j = 0; j < op.size(); j++) {
				string s1, s2;
				long long num1, num2, check = 0, res;
				s1 = op[j].substr(0, 3);

				if (s1 == "POP") {
					if (s.size() < 1)
					{
						flag = false;
						cout << err << '\n';
						break;
					}
					s.pop();
				}
				else if (s1 == "INV") {
					if (s.size() < 1)
					{
						flag = false;
						cout << err << '\n';
						break;
					}
					num1 = s.top();
					s.pop();
					s.push(num1 *-1);
				}
				else if (s1 == "DUP") {
					if (s.size() < 1)
					{
						flag = false;
						cout << err << '\n';
						break;
					}
					num1 = s.top();
					s.push(num1);
				}
				else if (s1 == "SWP") {
					if (s.size() < 2) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num1 = s.top();
					s.pop();
					num2 = s.top();
					s.pop();
					s.push(num1);
					s.push(num2);
				}
				else if (s1 == "ADD") {
					if (s.size() < 2) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num2 = s.top();
					s.pop();
					num1 = s.top();
					s.pop();
					res = num1 + num2;
					if (llabs(res) > pow(10, 9)) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.push(res);
				}
				else if (s1 == "SUB") {
					if (s.size() < 2) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num2 = s.top();
					s.pop();
					num1 = s.top();
					s.pop();
					res = num1 - num2;
					if (llabs(res) > pow(10, 9)) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.push(res);
				}
				else if (s1 == "MUL") {
					if (s.size() < 2) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num2 = s.top();
					s.pop();
					num1 = s.top();
					s.pop();
					res = num1 * num2;
					if (llabs(res) > pow(10, 9)) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.push(res);
				}
				else if (s1 == "DIV") {
					if (s.size() < 2) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num2 = s.top();
					if (num2 == 0) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.pop();
					num1 = s.top();
					s.pop();
					if (num1 < 0) {
						check++;
					}
					if (num2 < 0) {
						check++;
					}
					res = llabs(num1) / llabs(num2);
					if (check == 1)
						res *= -1;
					if (llabs(res) > pow(10, 9)) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.push(res);
				}
				else if (s1 == "MOD") {
					if (s.size() < 2) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num2 = s.top();
					s.pop();
					if (num2 == 0) {
						flag = false;
						cout << err << '\n';
						break;
					}
					num1 = s.top();
					s.pop();
					res = llabs(num1) % llabs(num2);
					if (num1 < 0)
						res *= -1;
					if (llabs(res) > pow(10, 9)) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.push(res);
				}
				else {
					s2 = op[j].substr(4);
					num1 = stoll(s2);
					if (llabs(num1) > pow(10, 9)) {
						flag = false;
						cout << err << '\n';
						break;
					}
					s.push(num1);
				}
			}
			if (s.size() == 1 && flag) {
				cout << s.top() << '\n';
			}
			else {
				if (flag)
					cout << err << '\n';
			}
		}
		cout << "\n";
	}

}