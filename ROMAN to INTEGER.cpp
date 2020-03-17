/*
	ROMAN to INTEGER
	Link: https://www.interviewbit.com/problems/roman-to-integer/
*/

map<char, int> mp;

int Solution::romanToInt(string A) {
    mp['M'] = 1000, mp['D'] = 500, mp['C'] = 100, mp['L'] = 50, mp['X'] = 10, mp['V'] = 5, mp['I'] = 1;
    int res = 0;
    char p = 'I';
    for(int i = A.size() - 1; i >= 0; i--) {
        res = mp[A[i]] < mp[p] ? res - mp[A[i]] : res + mp[A[i]];
        p = A[i];
    }
    return res;
}