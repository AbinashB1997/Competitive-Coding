#include<bits/stdc++.h>

using namespace std;

void PrintEquilibrium()
{
    int N; cin >> N;
    bool Ok = true;
    int sum = 0, leftsum = 0;

    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i : a) {
        sum += i;
    }
    for(int i = 0; i < N; i++) {
        sum -= a[i];
        if(sum == leftsum) {
            cout << i + 1 << '\n';
            Ok = false;
            break;
        }
        leftsum += a[i];
    }
    if(Ok) {
        cout << -1 << '\n';
    }
}

int main()
{
    int tt; cin >> tt;
    while(tt--) {
        PrintEquilibrium();
    }
}