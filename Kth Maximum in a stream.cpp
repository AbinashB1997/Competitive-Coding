/*
	Kth maximum of each number in a stream
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define li unsigned long long int
#define pb push_back
#define fastIO std::ios_base::sync_with_stdio(false), cin.tie(NULL)
#define test int t;cin >> t;while(t--){solve();}
#define MOD 1000000007
#define f first
#define s second
#define loop(i, a, b) for(i = a; i < b; i++)

void swap(int *a, int *b) {
	*a ^= *b ^= *a ^= *b;
}

void heapify(int * heap, int k, int i) {
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int smallest = i;
    if(left_child < k && heap[left_child] < heap[smallest]) {
        smallest = left_child;
    }
    if(right_child < k && heap[right_child] < heap[smallest]) {
        smallest = right_child;
    }
    if(smallest != i) {
        swap(&heap[smallest], &heap[i]);
        heapify(heap, k, smallest);
    }
}

void insert(int * heap, int k, int n) {
    heap[0] = n;
    heapify(heap, k, 0);
}

void solve()
{
    int k, n; cin >> k >> n;
    int heap[k];
    for(int i = 0; i < k; i++) {heap[i] = -1;}
    int number_of_elements = -1;
    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        number_of_elements++;
        if(data > heap[0]) {
            insert(heap, k, data);
        }
        if(number_of_elements+1>=k){
            cout<<heap[0]<< ' ';
        }
        else{
            cout<<"-1"<<' ';
        }
    }
    cout << endl;
}

int main()
 {
	fastIO;
	test
	return 0;
}