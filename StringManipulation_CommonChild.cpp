// StringManipulation_CommonChild.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
	int l1 = s1.length();
	int l2 = s2.length();

	vector<vector<int>> vec(l1 + 1, vector<int>(l2 + 1));

	for (size_t i = 0; i < l1 + 1; i++) {
		vec[i][0] = 0;
	}

	for (size_t i = 0; i < l2 + 1; i++) {
		vec[0][i] = 0;
	}

	for (size_t i = 1; i < l1 + 1; i++) {
		for (size_t j = 1; j < l2 + 1; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				vec[i][j] = vec[i - 1][j - 1] + 1;
			}
			else {
				vec[i][j] = max(vec[i - 1][j], vec[i][j - 1]);
			}
		}
	}
	return vec[l1][l2];
}

int main()
{
	string s1;
	getline(cin, s1);

	string s2;
	getline(cin, s2);

	int result = commonChild(s1, s2);

	cout << result << "\n";

	return 0;
}