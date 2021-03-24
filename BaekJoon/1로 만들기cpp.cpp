#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;
int arr[30001];
int n;

int main() {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		
		arr[i] = arr[i - 1] + 1;

		if(arr[i] % 2 == 0) 
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (arr[i] % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		if (arr[i] % 5 == 0)
			arr[i] = min(arr[i], arr[i / 5] + 1);
	}

	cout << arr[n] << endl;
	return 0;
}