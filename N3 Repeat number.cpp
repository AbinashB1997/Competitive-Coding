/*
	Find the number that is repeated more than N/3 times in a given array with O(N) time and O(1) space;
	Link: https://www.interviewbit.com/problems/n3-repeat-number/
*/

int Solution::repeatedNumber(const vector<int> &arr) {
    if(arr.size() == 1) {
        return arr[0];
    }
    int first = INT_MAX, second = INT_MAX;
    int count1 = 0, count2 = 0;
    for(int i = 1; i < arr.size(); i++) {
        if(first == arr[i]) {
            count1++;
        }else if(second == arr[i]) {
            count2++;
        }else if(count1 == 0) {
            count1++;
            first = arr[i];
        }else if(count2 == 0) {
            count2++;
            second = arr[i];
        }else {
            count1--, count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < arr.size(); i++) { 
        if (arr[i] == first) {
            count1++; 
        }else if (arr[i] == second) {
            count2++; 
        }
    }
    if (count1 > arr.size() / 3) {
        return first; 
    }
  
    if (count2 > arr.size() / 3) {
        return second; 
    }
    return -1; 
}