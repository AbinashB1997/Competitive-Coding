#include<bits/stdc++.h>

using namespace std;

void Solve()
{
    //WRITE YOUR CODE HERE
    int N, SUM; cin >> N >> SUM;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int curr_Sum = 0;
    bool Ok = false;
    unordered_map<int, int>mp;
    for(int i = 0; i < N; i++) {
        curr_Sum += a[i];
        if(curr_Sum == SUM) {
            Ok = true;
            cout << 1 << ' ' << i + 1 << '\n';
            break;
        }
        if(mp.find(curr_Sum - SUM) != mp.end()) {
            Ok = true;
            cout << mp[curr_Sum - SUM] + 1 << ' ' << i + 1 << '\n';
            break;
        }
        mp[curr_Sum] = i + 1;
    }
    if(!Ok) {
        cout << -1 << '\n';
    }
}

int main()
{
    Solve();
}