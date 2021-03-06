#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

vector<string> split_string(string);
vector<string> results;

void minimumBribes(vector<int> q) {
	int bribeCount = 0;

	for (int i = q.size() - 1; i >= 0; i--)
	{
		if (q[i] > (i + 1) && q[i] - (i + 1) > 2) {
			results.push_back("Too chaotic");
			return;
		}

		int initJ = q[i] - 2 < 0 ? 0 : q[i] - 2;
		for (int j = initJ; j < i; j++)
		{
			if (q[j] > q[i])
				bribeCount++;
		}
	}
	results.push_back(to_string(bribeCount));
}

int main()
{
	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string q_temp_temp;
		getline(cin, q_temp_temp);

		vector<string> q_temp = split_string(q_temp_temp);

		vector<int> q(n);

		for (int i = 0; i < n; i++) {
			int q_item = stoi(q_temp[i]);

			q[i] = q_item;
		}

		minimumBribes(q);
	}

	for (string s : results)
	{
		cout << s << '\n';
	}
	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
