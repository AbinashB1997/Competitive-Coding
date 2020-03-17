/*
	Smallest missing positive number in an array in O(N) TC and O(1) SC
	Link: https://www.interviewbit.com/problems/first-missing-integer/
*/

int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0; i < A.size(); i++) {
        while(A[i] > 0 and A[i] <= A.size() and A[i] != A[A[i] - 1]) {
            swap(A[i], A[A[i] - 1]);
        }
    }
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != i+1) {
            return i+1;
        }
    }
    return A[A.size() - 1] + 1;
}