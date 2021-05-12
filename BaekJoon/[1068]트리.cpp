#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, root, node, del, leaf;
vector<int> p[51];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<int> q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> node;
		if (node == -1) // root �� ���
			root = i;
		else {
			p[node].push_back(i);
		}
	}
	cin >> del;
	if (del == root) // ���� �����ϴ� ��尡 root�� ��� leaf�� 0
		cout << 0;
	else {
		bool flag = true;
		for (int i = 0; i < p[root].size(); i++) { // root�� �ڽ� �� ��ŭ �ݺ��� ����
			int r = p[root][i];

			if (r == del) continue; //��Ʈ�� �ڽ��� ������ ���

			if (p[r].size() == 0) { // ��Ʈ�� �ڽ��� ���� ����� ���
				flag = false;
				leaf++;
				continue;
			}
			q.push(r);
			while (!q.empty()) {
				flag = false;
				int q_size = q.size();
				for (int j = 0; j < q_size; j++) {
					int parent = q.front(), c_cnt = 0;
					q.pop();
					for (int k = 0; k < p[parent].size(); k++) {
						int child = p[parent][k];
						if (child == del) continue;
						q.push(child);
						c_cnt++; // �ڽ��� �����Ǿ� ������ ���� ��尡 �� �� �����Ƿ� �ڽ��� ���� Ȯ��
					}
					if (c_cnt == 0) {
						leaf++;
					}
				}

			}
		}
		if (flag) // ���� ��Ʈ�� ���� ��尡 �� ���
			leaf++;
		cout << leaf;
	}
	return 0;
}