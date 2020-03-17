#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tt; cin >> tt;
    while(tt--) {
        int N; cin >> N;
        vector<int>a(N);
        for(int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if(!(N & 1)) {
            cout << 0 << '\n';
        }else {
            int x = 0;
            for(int i = 0; i < N; i += 2) {
                x ^= a[i];
            }
            cout << x << '\n';
        }
    }
    return 0;
}