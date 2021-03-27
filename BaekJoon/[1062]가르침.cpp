#include <iostream>
#include <vector>
#include <string>

using namespace std;

int visited[26];
vector<string> words;
int max_num;
int N, K, check;
string input;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void dfs(int num) {
	visited[num] = 1;
	check--;
	if (check == 0) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			string word = words[i];
			bool flag = true;
			for (int y = 0; y < word.length(); y++) {
				if (visited[word[y] - 'a'] == 0) {
					flag = false;
					break;
				}
			}
			if (flag)
				count++;
		}
		if (count > max_num)
			max_num = count;
		visited[num] = 0;
		check++;
		return;
	}
	else {
		for (int i = num + 1; i < 26; i++) {
			if (visited[i] == 0) {
				dfs(i);
			}
		}
		visited[num] = 0;
		check++;
	}

}

int main() {
	init();
	visited['a' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;


	cin >> N >> K;
	check = K - 5;
	for (int i = 0; i < N; i++) {
		cin >> input;
		words.push_back(input);
	}
	if (K < 5) {
		cout << "0" << endl;
		return 0;
	}
	if (K == 5) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			string word = words[i];
			bool flag = true;
			for (int y = 0; y < word.length(); y++) {
				if (visited[word[y] - 'a'] == 0) {
					flag = false;
					break;
				}
			}
			if (flag)
				count++;
		}
		if (count > max_num)
			max_num = count;
		cout << max_num << endl;
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (visited[i] == 0) {
				dfs(i);
			}
		}

		cout << max_num << endl;
	}
	return 0;
}