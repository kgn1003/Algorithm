#include <string>
#include <set>

using namespace std;
int solution(string dirs) {
	set<pair<pair<int, int>, pair<int, int>>> move;
	int cy = 0, cx = 0, ny, nx;
	for (int i = 0; i < dirs.length(); i++) {
		char d = dirs[i];
		if (d == 'U') {
			ny = cy + 1; nx = cx;
			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // ��ǥ ��踦 �Ѿ� ���� ������
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // ������ ��ġ�°� ���� �ϴ��� Ȯ��.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cy += 1;
			}
		}
		else if (d == 'D') {
			ny = cy - 1; nx = cx;
			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // ��ǥ ��踦 �Ѿ� ���� ������
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // ������ ��ġ�°� ���� �ϴ��� Ȯ��.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cy -= 1;
			}
		}
		else if (d == 'R') {
			ny = cy; nx = cx + 1;

			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // ��ǥ ��踦 �Ѿ� ���� ������
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // ������ ��ġ�°� ���� �ϴ��� Ȯ��.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cx += 1;
			}
		}
		else {
			ny = cy; nx = cx - 1;
			if (ny >= -5 && ny <= 5 && nx >= -5 && nx <= 5) { // ��ǥ ��踦 �Ѿ� ���� ������
				if (!move.count({ {cy,cx}, {ny,nx} }) && !move.count({ {ny,nx},{cy,cx} })) { // ������ ��ġ�°� ���� �ϴ��� Ȯ��.
					move.insert({ {cy,cx}, {ny,nx} });
				}
				cx -= 1;
			}
		}
	}
	return move.size();
}