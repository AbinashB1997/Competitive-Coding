#include<bits/stdc++.h>

using namespace std;

// Logic : We are actually Make window, in such a way that the next sub array sum will be the add of next element and minus
// of previous starting element. As rest all the element are common. O(N) Solution

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int>prefix(N - K + 1);
    int sum = std::accumulate(a.begin(), a.begin()+K, 0);
    int p = K;
    prefix[0] = sum;
    for(int i = 1; i < N - K + 1; i++) {
        prefix[i] = prefix[i - 1] - a[i - 1] + a [p];
        p++;
    }
    cout << *max_element(prefix.begin(), prefix.end()) << '\n';
}