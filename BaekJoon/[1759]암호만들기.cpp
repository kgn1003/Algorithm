#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int L, C;
char arr[15];
bool selected[15], alphabet[26];

void DFS(int idx, int cnt) {
	if (cnt == L) {
		string password = "";
		int temp = cnt, i = 0, check = 0;
		bool flag = false;
		while (temp > 0) {
			if (selected[i] == true) {
				if (alphabet[arr[i] - 'a'] == true) {
					flag = true;
				}
				else
				{
					check++;
				}
				password += arr[i];
				temp--;
			}
			i++;
		}
		if (flag && check >= 2) {
			cout << password << "\n";
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		if (selected[i] == true) continue;
		selected[i] = true;
		DFS(i, cnt + 1);
		selected[i] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	alphabet['a' - 'a'] = true;
	alphabet['e' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['o' - 'a'] = true;
	alphabet['u' - 'a'] = true;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);
	DFS(0, 0);
	return 0;
}