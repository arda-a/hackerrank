#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
	char currentChar = 'c';
	int counter = 0;
	for (size_t i = 0; i < s.length(); i++) {
		if (currentChar == (char)s[i]) {
			counter++;
		}
		currentChar = (char)s[i];
	}
	return counter;
}

int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		getline(cin, s);

		int result = alternatingCharacters(s);

		cout << result << "\n";
	}

	return 0;
}