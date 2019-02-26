
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
	int n = c.size();
	sort(c.begin(), c.end());
	int cost = 0;
	for (size_t i = 0; i < n; i++) {
		cost += c[n - i - 1] * (i / k + 1);
	}	

	return cost;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	vector<int> c(n);

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int minimumCost = getMinimumCost(k, c);

	cout << minimumCost << "\n";

	return 0;
}