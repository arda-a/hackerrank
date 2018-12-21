#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	map<char, int> c_map;
	for (size_t i = 0; i < s.length(); i++) {
		c_map[s[i]]++;
	}

	map<int, int> countMap;
	for (auto& val : c_map) {
		countMap[val.second]++;
	}


	if (countMap.size() == 1)
		return "YES";
	else if (countMap.size() == 2 && any_of(countMap.begin(), countMap.end(), [](pair<int, int> p) { return p.second == 1; })) {
		bool any = any_of(countMap.begin(), countMap.end(), [](pair<int, int> p) { return p.second == 1 && p.first == 1; });
		if (any)
			return "YES";

		auto it = countMap.begin();
		int firstKey = (*it++).first;
		int secondKey = (*it).first;
		int multiplator = countMap[firstKey] == 1 ? -1 : 1;
		if ((secondKey - firstKey) * multiplator != 1)
			return "NO";

		return "YES";
	}

	return "NO";
}

int main()
{
	string s;
	getline(cin, s);

	string result = isValid(s);

	cout << result << "\n";

	return 0;
}