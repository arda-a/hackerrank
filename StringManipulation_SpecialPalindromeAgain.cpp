// StringManipulation_SpecialPalindromeAgain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
	int count = 1;
	long ans = 0;
	char current = '\0';
	vector<pair<char, int>> charVec;
	for (size_t i = 0; i < n; i++) {
		if (s[i] == current) {
			count++;
		}
		else {
			if (current != '\0') {
				charVec.push_back(pair<char, int>(current, count));
			}
			count = 1;
			current = s[i];
		}
	}
	charVec.push_back(pair<char, int>(current, count));

	for (auto & val : charVec) {
		ans += (val.second * (val.second + 1)) / 2;
	}

	for (size_t i = 1; i < charVec.size() - 1; i++) {
		if (charVec[i].second == 1 && charVec[i - 1].first == charVec[i + 1].first) {
			ans += min(charVec[i - 1].second, charVec[i + 1].second);
		}
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(cin, s);

	long result = substrCount(n, s);

	cout << result << "\n";

	return 0;
}
