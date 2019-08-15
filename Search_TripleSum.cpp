#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  a.erase(unique(a.begin(), a.end()), a.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  long totalCount = 0;
  for (size_t i = 0; i < b.size(); i++) {
    long cnt_a = 0, cnt_b = 0;

    cnt_a = std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), b[i]));
    cnt_b = std::distance(c.begin(), std::upper_bound(c.begin(), c.end(), b[i]));

    totalCount += cnt_a * cnt_b;
  }

  return totalCount;
}

int main()
{
  int lena, lenb, lenc;
  cin >> lena >> lenb >> lenc;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  vector<int> arra(lena);
  for (int i = 0; i < lena; i++) {
    cin >> arra[i];
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');


  vector<int> arrb(lenb);
  for (int i = 0; i < lenb; i++) {
    cin >> arrb[i];
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');


  vector<int> arrc(lenc);
  for (int i = 0; i < lenc; i++) {
    cin >> arrc[i];
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  long ans = triplets(arra, arrb, arrc);
  cout << ans << "\n";

  return 0;
}
