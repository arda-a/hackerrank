#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b)
{
	int aSizeInit = a.size();
	int bSizeInit = b.size();

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	char a_c[10000];
	strcpy(a_c, a.c_str());

	char b_c[10000];
	strcpy(b_c, b.c_str());


	vector<string> sameLetters;
	for (int i = 0; i < aSizeInit; i++)
	{
		for (int j = 0; j < bSizeInit; j++)
		{
			if (a_c[i] == b_c[j])
			{
				if (find(sameLetters.begin(), sameLetters.end(), to_string(i) + a_c[i]) == sameLetters.end()) // does not contain
				{
					sameLetters.push_back(to_string(i) + a_c[i]);
					b_c[j] = NULL;
					break;
				}
			}
		}
	}

	return a.size() + b.size() - (sameLetters.size() * 2);
}

int main() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	return 0;
}
