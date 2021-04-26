#include <algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), cmp);
	int v_size = A.size();
	for (int i = 0; i < v_size; i++) {
		answer += A[i] * B[i];
	}
	return answer;
}