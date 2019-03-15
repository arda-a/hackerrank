// Miscellaneous_FlippingBits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Complete the flippingBits function below.
long long flippingBits(unsigned int dec) {
	long long result = 0;
	//int digits = floor(log10(dec) / log10(2)) + 1;
	int totalDigits = 32;
	vector<int> bin(totalDigits);
	for (size_t i = 0; i < totalDigits; i++) {
		bin[i] = 0;
	}
	int j = totalDigits -1;
	while (dec != 0) {
		bin[j--] = dec % 2;
		dec /= 2;
	}

	for (size_t i = 0; i < 32; i++) {
		int val = bin[i];
		bin[i] = val == 0 ? 1 : 0;
		if (bin[i] != 0)
			result += pow(2.0, 31 - i);
	}

	return result;
}

int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		unsigned int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		long long result = flippingBits(n);

		cout << result << "\n";
	}

	return 0;
}
