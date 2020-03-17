#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tt; cin >> tt; 
    while(tt--) {
        int N; cin >> N;
        int even_wala = N & 0xAAAAAAAA;
        int odd_wala = N & 0x55555555;
        even_wala >>= 1;
        odd_wala <<= 1;
        cout << (even_wala | odd_wala) << '\n';
    }
    return 0;
}