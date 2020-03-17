/*
	Max area to contain the water. water area problem
    Link: https://www.interviewbit.com/problems/container-with-most-water/
*/

int Solution::maxArea(vector<int> &A) {
    int left = 0, right = A.size() - 1, area = 0;
    while(left < right) {
        area = max(area, min(A[left], A[right]) * (right - left));
        if(A[left] < A[right]) {
            left++;
        }else {
            right--;
        }
    }
    return area;
}