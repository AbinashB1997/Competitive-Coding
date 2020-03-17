/*
    All element occur thrice except one, tell which one is that in O(N) Time and O(1) Space
	Link: https://www.interviewbit.com/problems/single-number-ii/
*/

int Solution::singleNumber(const vector<int> &A) {
    int res = 0;
    for(int i = 0; i <= 31; i++) {
        int count = 0;
        int x = 1 << i;
        for(int j = 0; j < A.size(); j++) {
            if(A[j] & x) {
                count++;
            }
        }
        if(count % 3) {
            res |= x;
        }
    }
    return res;
}