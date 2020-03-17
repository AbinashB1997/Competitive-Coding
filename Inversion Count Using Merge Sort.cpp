/*
	Inversion count
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll merge(ll arr[], ll temp[], ll start, ll mid, ll end) {
    ll i, j, k, inv = 0;
    i = k = start, j = mid;
    while(i < mid and j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }else {
            temp[k++] = arr[j++];
            inv += (mid - i);
        }
    }
    while(i < mid) {
        temp[k++] = arr[i++];
    }
    while(j <= end) {
        temp[k++] = arr[j++];
    }
    for(ll p = start; p <= end; p++) {
        arr[p] = temp[p];
    }
    return inv;
}

ll countInv(ll arr[], ll temp[], ll start, ll end) 
{
    ll inv = 0, mid;
    if(end > start) {
        mid = (start + end) / 2;
        inv = countInv(arr, temp, start, mid);
        inv += countInv(arr, temp, mid + 1, end);
        inv += merge(arr, temp, start, mid + 1, end);
    }
    return inv;
}

int main()
{
    int tt; cin >> tt;
    while(tt--) {
        ll N; cin >> N;
        ll arr[N], temp[N];
        for(ll i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cout << countInv(arr, temp, 0, N - 1) << endl;
    }
    return 0;
}