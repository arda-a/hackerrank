#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mergeHalves(std::vector<int> &arr, std::vector<int> &temp, long &count, int leftStart, int rightEnd) {
	int middle = (leftStart + rightEnd) / 2;
	int rightStart = middle + 1;
	int left = leftStart;
	int index = leftStart;
	int right = rightStart;
	while (left <= middle && right <= rightEnd) {
		if (arr[left] <= arr[right]) {
			temp[index++] = arr[left++];
		}
		else {
			temp[index++] = arr[right++];
			count += middle - left + 1;
		}
	}
	
	while (left <= middle)
		temp[index++] = arr[left++];
	while(right <= rightEnd)
		temp[index++] = arr[right++];
	
	for (size_t i = leftStart; i <= rightEnd; i++) {
		arr[i] = temp[i];
	}
}

void mergeSort(std::vector<int> &arr, std::vector<int> &temp, long &count, int leftStart, int rightEnd) {
	if (leftStart >= rightEnd)
		return;
	int middle = (leftStart + rightEnd) / 2;
	mergeSort(arr, temp, count, leftStart, middle);
	mergeSort(arr, temp, count, middle + 1, rightEnd);
	mergeHalves(arr, temp, count, leftStart, rightEnd);
}

long countInversions(vector<int> arr) {
	long count = 0;
	vector<int> temp(arr.size());
	mergeSort(arr, temp, count, 0, arr.size() - 1);

	return count;
}

int main()
{
	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (size_t i = 0; i < t; i++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		vector<int> vec(n);
		for (size_t j = 0; j < n; j++) {
			int val;
			cin >> val;
			vec[j] = val;
		}
		long result = countInversions(vec);
		cout << result << endl;
	}
	return 0;
}