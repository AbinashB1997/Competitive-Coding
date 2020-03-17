/*
	N-th Prime, by pre-processing
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long int
int main()
{
    ll test,i,j,a,b,ans;
    //cin>>test;
    vector<ll> arr(10000001,0);
    vector<ll> new_arr;
    for(ll i=2;i<10000001;i++)
    {
        if(arr[i]==0)
        {
            new_arr.push_back(i);
            for(ll j=i+i;j<=(10000001);j+=i)//remove multiples of prime numbers
                arr[j]=1;
        }
    }
    cin>>a;//input the positions of the number
    cout<<new_arr[a-1];//output in terms of nth prime number
}