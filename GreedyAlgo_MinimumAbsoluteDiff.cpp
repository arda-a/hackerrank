#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
	vector<int> diffVec;
	int minVal = -1;
	sort(arr.begin(), arr.end());
	for (size_t i = 1; i < arr.size() - 1; i++) {
		int localMin = min(abs(arr[i - 1] - arr[i]), abs(arr[i + 1] - arr[i]));
		if (i == 1)
			minVal = localMin;
		else
			minVal = min(localMin, minVal);
	}
	return minVal;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int result = minimumAbsoluteDifference(arr);

	cout << result << "\n";

	return 0;
}
