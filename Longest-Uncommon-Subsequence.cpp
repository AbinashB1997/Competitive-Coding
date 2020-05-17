#include<bits/stdc++.h>

using namespace std;

int LengthofLUS(string str1, string str2) {
  return (str1 == str2) ? -1 : max(str1.size(), str2.size());
}

int main()
{
  string str1, str2;
  cin >> str1 >> str2;
  cout << LengthofLUS(str1, str2);
  return 0;
}
