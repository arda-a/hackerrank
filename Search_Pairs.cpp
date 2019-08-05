// Search_Pairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int pairs(int k, vector<int> arr) {
  map<int, int> valMap;
  for (size_t i = 0; i < arr.size(); i++) {
    valMap[arr[i]]++;
  }
  int counter = 0;

  for (size_t i = 0; i < arr.size(); i++) {
    int requiredNumber = k + arr[i];
    if (valMap[requiredNumber] > 0) {
      counter += valMap[requiredNumber];
    }
  }

  return counter;
}

int main()
{
  int n, k;
  cin >> n >> k;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result = pairs(k, arr);

  cout << result << "\n";

  return 0;
}