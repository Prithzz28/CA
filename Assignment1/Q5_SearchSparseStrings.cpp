#include <bits/stdc++.h>
using namespace std;

//O(n^2)
int search(vector<string>&a,string x){
    int l=0,r=a.size()-1;
    while(l<=r){
        int m=(l+r)/2,i=m,j=m;
        while(true){
            if(i<l&&j>r)
                return -1;
            if(i>=l&&a[i]!=""){
                m=i;
                break;
            }
            if(j<=r&&a[j]!=""){
                m=j;
                break;
            }
            i--;
            j++;
        }
        if(a[m]==x)
            return m;
        if(a[m]<x)
            l=m+1;
        else 
            r=m-1;
    }
    return-1;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    string x;
    cin>>x;
    cout<<search(a,x);
}