#include "pch.h"
#include <iostream>
#include <vector>	
#include <string>
#include <array>
#include <queue>
#include <map>
#include <fstream>

using namespace std;

double getMedian(int d, std::vector<int> &countVec);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
	int counter = 0;
	queue<int> q;
	vector<int> countVec(201);
	for (size_t i = 0; i < expenditure.size(); i++) {
		if (i < d) {
			q.push(expenditure[i]);
			countVec[expenditure[i]]++;
			continue;
		}

		double median = getMedian(d, countVec);

		if (median * 2 <= expenditure[i])
			counter++;

		countVec[q.front()]--;
		countVec[expenditure[i]]++;
		q.pop();
		q.push(expenditure[i]);
	}
	return counter;
}

double getMedian(int d, std::vector<int> &countVec)
{
	if (d % 2 == 0) {
		int centerIndex = 0, first = 0, second = 0;
		for (size_t i = 0; i < countVec.size(); i++) {
			centerIndex += countVec[i];
			if (centerIndex == d / 2) {
				first = i;
			}
			else if (centerIndex > d / 2) {
				if (first == 0)
					first = i;
				second = i;
				return ((double)first + (double)second) / 2.0;
			}
		}
	}
	else {
		int centerIndex = 0;
		for (size_t i = 0; i < countVec.size(); i++) {
			centerIndex += countVec[i];
			if (centerIndex > d / 2)
				return i;
		}
	}
	return 0.0;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> expenditure(n);

	for (int i = 0; i < n; i++)
	{
		cin >> expenditure[i];
	}

	int result = activityNotifications(expenditure, d);

	cout << result << "\n";

	return 0;
}