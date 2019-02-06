#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
	int totalPoints = 0;
	vector<int> pointsVec(contests.size());
	for (size_t i = 0; i < contests.size(); i++) {
		pointsVec[i] = (contests[i][0]);
		if (contests[i][1] == 0)
			totalPoints += contests[i][0];
		else
			totalPoints -= contests[i][0];
	}
	sort(pointsVec.begin(), pointsVec.end());
	int counter = 0;
	for (size_t i = 0; i < contests.size(); i++) {
		for (size_t j = 0; j < contests.size(); j++) {
			if (counter == k) {
				return totalPoints;
			}
			else if (contests[j][0] == pointsVec[pointsVec.size() - 1 - i] && contests[j][1] == 1) {
				totalPoints += (pointsVec[pointsVec.size() - 1 - i] * 2);
				counter++;
				contests[j][0] = 0;
			}
		}
	}

	return totalPoints;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> contests(n);
	for (int i = 0; i < n; i++) {
		contests[i].resize(2);

		for (int j = 0; j < 2; j++) {
			cin >> contests[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = luckBalance(k, contests);

	cout << result << "\n";

	return 0;
}