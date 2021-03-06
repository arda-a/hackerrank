#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>


using namespace std;

unsigned findCombination(unsigned n, unsigned k) {
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	int result = n;
	for (int i = 2; i <= k; i++) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
	int count = 0;
	map<string, int> m_map;
	//const char *arr = s.c_str();
	for (size_t i = 0; i < s.length() - 1; i++) {
		string sum = "";
		sum += s[i];
		for (size_t j = i + 1; j < s.length(); j++) {
			if (s[i] == s[j]) {
				count++;
			}

			sum += s[j];
			sort(sum.begin(), sum.end());
			m_map[sum]++;
		}
	}
	for (auto& val : m_map) {
		if (val.second > 1)
			count += findCombination(val.second, 2);
	}

	return count;
}

int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string s;
		getline(cin, s);

		int result = sherlockAndAnagrams(s);

		cout << result << '\n';
	}

	return 0;
}