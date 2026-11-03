#include <bits/stdc++.h>
using namespace std;

//O(m+n)
double median(vector<int>&A,vector<int>&B){
    if(A.size()>B.size()) 
        return median(B,A);
    int m=A.size(),n=B.size(),l=0,r=m;
    while(l<=r){
        int i=(l+r)/2,j=(m+n+1)/2-i;
        int L1=i?A[i-1]:INT_MIN,R1=i<m?A[i]:INT_MAX;
        int L2=j?B[j-1]:INT_MIN,R2=j<n?B[j]:INT_MAX;
        if(L1<=R2&&L2<=R1){
            if((m+n)%2) 
                return max(L1,L2);
            return (max(L1,L2)+min(R1,R2))/2.0;
        }
        if(L1>R2) 
            r=i-1; 
        else    
            l=i+1;
    }
    return 0;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> A(m),B(n);
    for(int i=0;i<m;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    median(A,B);
}