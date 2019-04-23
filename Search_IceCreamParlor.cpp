// Search_IceCreamParlor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>

using namespace std;

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
	map<int, int> costMap;
	int firstIndex = -1, moneyNeeded = 0;

	for (size_t i = 1; i < cost.size() + 1; i++) {
		costMap[cost[i - 1]] = i;
	}

	for (size_t i = 0; i < cost.size(); i++) {
		moneyNeeded = money - cost[i];
		if (moneyNeeded > 0) {
			if (costMap[moneyNeeded] > 0 && costMap[moneyNeeded] != i + 1) {
				if (i + 1 < costMap[moneyNeeded])
					cout << to_string(i + 1) << " " << to_string(costMap[moneyNeeded]) << endl;
				else
					cout << to_string(costMap[moneyNeeded]) << " " << to_string(i + 1) << endl;
				break;
			}
		}
	}	
}

int main()
{
	std::ifstream in("in.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("out1.txt");
	std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int money;
		cin >> money;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		vector<int> cost(n);

		for (int i = 0; i < n; i++) {
			cin >> cost[i];
		}

		whatFlavors(cost, money);
	}

	return 0;
}