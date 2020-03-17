/*
	Max successive difference between element in an unsorted array in its sorted form 
	Note: We don't need to sort it to do solve the question
	Problem: 
*/

int Solution::maximumGap(const vector<int> &arr) {
    if(arr.size() < 2) {
        return 0;
    }
    vector<int> Smaller(arr.size(), -1), Larger(arr.size(), -1);
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());
    int gap = (max - min) / (arr.size() - 1);
    if(gap == 0) {
        return max - min;
    }
    int max_gap = 0; 
    for(int i = 0; i < arr.size(); i++) {
        int bucket = (arr[i] - min) / gap;
        if(Smaller[bucket] < 0) {
            Smaller[bucket] = Larger[bucket] = arr[i];
        }else {
            Smaller[bucket] = std::min(Smaller[bucket], arr[i]);
            Larger[bucket] = std::max(Larger[bucket], arr[i]);
        }
    }
    int idx = 0;
    for(int i = 0; i < Smaller.size(); i++) {
        if(Smaller[i] >= 0) {
            max_gap = std::max(max_gap, Smaller[i] - Larger[idx]);
            idx = i;
        }
    }
    
    return max_gap;
}