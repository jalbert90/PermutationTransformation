#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void roots(int low, int high, int depth, vector<int>& a, vector<int>& d) {
	if (low <= high) {
		int r, ri;

		r = *max_element(a.begin() + low, a.begin() + high + 1);
		ri = find(a.begin() + low, a.begin() + high + 1, r) - a.begin();

		d[ri] = depth;

		depth++;

		roots(low, ri - 1, depth, a, d);
		roots(ri + 1, high, depth, a, d);
	}
	else {
		return;
	}
}

void execute() {
	int n;
	vector<int> a;
	vector<int> d;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		a.push_back(input);
		d.push_back(0);
	}

	int iR = *max_element(a.begin(), a.end());
	int iRIndex = find(a.begin(), a.end(), iR) - a.begin();

	int depth = 1;

	roots(0, iRIndex - 1, depth, a, d);
	roots(iRIndex + 1, n - 1, depth, a, d);

	for (int i = 0; i < n; i++) {
		cout << d[i] << " ";
	}

	cout << endl;
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		execute();
	}
}