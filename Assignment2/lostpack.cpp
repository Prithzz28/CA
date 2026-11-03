#include <bits/stdc++.h>
using namespace std;

//O(N)
int main(){
    int n;
    cin>>n; 
    vector<int>a(n);
    for(int&i:a)
    cin>>i;
    for(int i=1;i<n;i++){ 
        if(a[i]-a[i-1]>1){ 
            cout<<a[i-1]+1; 
            return 0; 
        }
    }
    cout<<"No missing";
}