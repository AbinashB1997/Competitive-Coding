#include<bits/stdc++.h>
using namespace std;

void printPowerSet(string S, int N, string a[]){
    long int size = (long int)pow(2, N);
    int k = 0;
    for(long int i = 0; i < size; i++){
        for(int j = 0; j < N; j++){
            if(i & (1<<j)){
                a[k] = a[k] + S[j]; 
            } 
        }
    k++;
    }
}
int main() { 
    int T; 
    cin >> T;
    while(T--)
    {
        int N; 
        cin>>N;
        string S;
        cin >> S;
        string a[(long int)pow(2, N)];
        printPowerSet(S, N, a);
        sort(a, a+sizeof(a)/sizeof(a[0]));
        for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
            if(a[i] != ""){
                cout<<a[i]<<" ";
            } 
        }
        cout<<endl; 
    } 
return 0;
}