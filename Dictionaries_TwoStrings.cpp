#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <array>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
	map<char, int> dict;

	for (size_t i = 0; i < s1.length(); i++) {
		if (dict[(char)s1[i]] == 0)
			dict[(char)s1[i]]++;
	}
	for (size_t i = 0; i < s2.length(); i++) {
		if (dict[(char)s2[i]] > 0)
			return "YES";
	}
	return "NO";
}

int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s1;
		getline(cin, s1);

		string s2;
		getline(cin, s2);

		string result = twoStrings(s1, s2);

		cout << result << endl;
	}

	return 0;
}