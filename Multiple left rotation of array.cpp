/*
	Rotate left an array by 3 units in O(Q*N) solution for multiple queries
	Link: https://www.interviewbit.com/problems/multiple-left-rotations-of-the-array/
*/

vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    vector<vector<int> > ans;
    ans.resize(B.size());
    long int n = A.size();
    for(int i = 0; i < B.size(); i++) {
        ans[i].resize(n);
        int mod = B[i] % n;
        for(int j = 0; j < n; j++) {
            ans[i][j] = A[(mod + j) % n];
        }
    }
    return ans; 
}