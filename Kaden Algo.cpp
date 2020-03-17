/*
	Kaden's Algorithm
*/

bool AllNeg(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		if(arr[i] > 0) {
			return false;
		}
	return true;
}

int maxSumSubarray(int arr[], int n) {
	// Base Case: All neg, then return the maximum 
	if(AllNeg(arr, n)) {
		return *max_element(arr, arr + n);
	}
	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		a += arr[i];
		if(a < 0) {
			a = 0;
		}
		b = max(a, b);
	}
	return b;
}