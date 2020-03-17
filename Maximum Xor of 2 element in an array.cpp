int Solution::solve(vector<int> &A) {
    int mask = 0, Max = 0;
    unordered_map<int, int> mp;
    for(int i = 31; i >= 0; i--) {
        mp.clear();
        mask |= 1 << i;
        for(int j = 0; j < A.size(); j++) {
            mp[A[j] & mask] = 1;
        }
        int m = Max | 1 << i;
        for(auto bits : mp) {
            if(mp.find(m ^ bits.first) != mp.end()) {
                Max = m;
                break;
            }
        }
    }
    return Max;
}