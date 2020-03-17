// Minimum insertion at beginning to make the given string pallindrome. And return the pallindromic string. 
#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll dp[100000]; // This array will contain the total matching characters. Trouble in understanding ?? Don't worry. 

void makePalindrome(string sss) {
	dp[0] = 0; // Make it 0, because we will be filling the array from jth Position.
	int i = 0, j = 1; // Two pointer approach. one at beggining and other at second pos
    while(j < sss.size()) {
		if(sss[i] == sss[j]) {
			dp[j] = i + 1;
			i++, j++;
		} else if(i > 0) {
			i = dp[i - 1]; // In case i travelled so far and we might miss some character to compare with, so move i back.
		} else {
			dp[j] = 0;
			j++;
		}
	}
}

int main()
{
	string sss; cin >> sss;
	string rev = sss; 
	reverse(rev.begin(), rev.end());
    sss = sss + '#' + rev; // Just append any character between the original and reversed string. And let's get started. :)
	makePalindrome(sss);
	int lastValue = dp[sss.size() - 1];
	int MinCharNeed = rev.size() - lastValue;
	string Pallindromic_string = rev.substr(0, MinCharNeed);
	cout << "Min character required = " << MinCharNeed << " String is " << Pallindromic_string;
	return 0;
}