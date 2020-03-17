/*
	Sum of bit wise OR of all the subarrays of the array
    Link: https://www.hackerrank.com/contests/codeagon/challenges/bob-and-subarray-or
*/

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli n, tmp;
int idx[50];
int main(){
    lli ans = 0; cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> tmp;
        for(int j=0; j<=31; ++j){
            lli pw = 1l << j;
            if(tmp & pw){        // Checking if the pw-th bit is set or not.
                ans += pw * i;
                idx[j] = i;
            } else if(idx[j]){
                ans += pw * idx[j];
            }
        }
    }
    cout << ans << endl;

    return 0;
}