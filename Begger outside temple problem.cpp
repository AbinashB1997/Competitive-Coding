/*
	Begger outside temple problem
*/

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> paisa(A, 0);
    for(int i = 0; i < B.size(); i++) { 
        paisa[B[i][0] - 1] += B[i][2];
        if (B[i][1] < A) {
            paisa[B[i][1]] -= B[i][2];
        }
    }
    for(int i = 1; i < A; i++) {
        paisa[i] = paisa[i] + paisa[i - 1];
    }
    return paisa;
}