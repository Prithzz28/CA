#include <bits/stdc++.h>
//O(1)
using namespace std;
int main(){
    long long N,K; 
    cin>>N>>K;
    if(N==1){ 
        cout<<1; 
        return 0; 
    }
    long long c=2*N-2;
    long long p=(K-1)%c+1;
    if(p<=N) 
        cout<<p;
    else 
        cout<<2*N-p;
}