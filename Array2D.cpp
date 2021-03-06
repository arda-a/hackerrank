// Array2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include "Array2D.h"

using namespace std;

vector<int> _hourglassList;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			int hourglassVal = arr[i][j] + arr[i][j + 1] + arr[i][j  + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
			_hourglassList.push_back(hourglassVal);
		}
	}

	int result = *max_element(_hourglassList.begin(), _hourglassList.end());
	return result;
}


int main()
{
	vector<vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}


	int result = hourglassSum(arr);
	cout << result << "\n";

	string str;
	getline(cin, str);

	return 0;
}
