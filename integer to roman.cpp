/*
	INTEGER to ROMAN-NUMBER
	Link: https://www.interviewbit.com/problems/integer-to-roman/
*/

string m[] = {"", "M", "MM", "MMM"};
string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 
string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 

string Solution::intToRoman(int A) {
    return (m[A / 1000] + c[(A % 1000) / 100] + x[(A % 100) / 10] + i[A % 10]); 
}