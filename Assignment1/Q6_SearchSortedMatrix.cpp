#include <bits/stdc++.h>

//O(N)
using namespace std;
int main(){
    int m,n,x;
    cin>>m>>n;
    vector<vector<int>>a(m,vector<int>(n));
    for(auto&r:a)
        for(int&v:r)
            cin>>v;
    cin>>x;
    int i=0,j=n-1;
    while(i<m&&j>=0){
        if(a[i][j]==x){
            cout<<i<<" "<<j;
            return 0;
        }
        if(a[i][j]>x)
            j--;
        else
            i++;
    }
    cout<<"Not Found";
}