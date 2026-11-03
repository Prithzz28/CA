#include <bits/stdc++.h>
using namespace std;

//O(n)
int search(vector<int>&a,int t){
    int l=0,r=a.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==t)
            return m;
        if(a[l]<=a[m]){
            if(t>=a[l]&&t<a[m])
                r=m-1;
            else l=m+1;
        }
        else{
            if(t>a[m]&&t<=a[r])
                l=m+1;
            else 
                r=m-1;
        }
    }
    return -1;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    for(int&i:a)
        cin>>i;
    cout<<search(a,t);
}