/*
	Gray Code
	Link: https://www.interviewbit.com/problems/gray-code/
*/

vector<int> Solution::grayCode(int A) {
    vector<int> res;
    for (auto i = 0; i < (1L << A); i++) {
        res.push_back((i ^ (i >> 1)));
    }
    return res;
}