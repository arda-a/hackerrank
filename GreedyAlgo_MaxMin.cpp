// GreedyAlgo_MaxMin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int min = -1;
	for (size_t j = 0; j < arr.size() - k + 1; j++) {
		int current = arr[k + j - 1] - arr[j];
		if (current == 0)
			return current;
		if (min == -1)
			min = current;
		else if (min > current) 
			min = current;
	}

	return min;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[i] = arr_item;
	}

	int result = maxMin(k, arr);

	cout << result << "\n";
	return 0;
}