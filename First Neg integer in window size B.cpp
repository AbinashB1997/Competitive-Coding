/*
	First -ve integer in window size B
*/

vector<int> Solution::solve(vector<int> &A, int B) {
    vector<int> ans;
    deque<int> DQ;
    for(int i = 0; i < B; i++) {
        if(A[i] < 0) {
            DQ.push_back(i);
        }
    }
    for(int i = B; i < A.size(); i++) {
        if(!DQ.empty()) {
            ans.push_back(A[DQ.front()]);
        }else {
            ans.push_back(0);
        }
        if(!DQ.empty() and DQ.front() < i - B + 1) {
            DQ.pop_front();
        }
        if(A[i] < 0) {
            DQ.push_back(i);
        }
    }
    if(!DQ.empty()) {
        ans.push_back(A[DQ.front()]);
    }else {
        ans.push_back(0);
    }
    return ans;
}