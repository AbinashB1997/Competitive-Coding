#include<bits/stdc++.h>

using namespace std;

int SUBARRAY(int arr[], int size, int sum) 
{ 
    int Sum_Now = arr[0], start = 0, i; 
    for (i = 1; i <= size; i++) {
        while (start < i-1 && Sum_Now > sum) { 
            Sum_Now -= arr[start++]; 
        }
        if (Sum_Now == sum) { 
            cout << start + 1 << ' ' << i << '\n'; 
            return 1; 
        } 
        if (i < size) {
            Sum_Now += arr[i]; 
        }
    } 
    cout << -1 << '\n';
    return 0; 
} 

int main()
 {
	int tt; cin >> tt; 
	while(tt--) {
	    int N, sum; cin >> N >> sum;
	    int arr[N];
	    for(int i = 0; i < N; i++) {
	        cin >> arr[i];
	    }
	    SUBARRAY(arr, N, sum);
	}
	return 0;
}